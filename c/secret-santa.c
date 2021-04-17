#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <errno.h>


int main(int argc, char const *argv[]) {
    FILE *roster;
    if ((roster = fopen("roster.txt", "r")) == NULL) {
        fprintf(stderr, "Error: Could not open '%s'. %s.\n", "roster.txt", strerror(errno));
        return EXIT_FAILURE;
    }
    
    int lines = 0;
    char buf[256];
    while(fgets(buf, sizeof(buf), roster) != NULL) {
        lines++;
    }
    buf[strcspn(buf, "\n")] = 0;
    if (lines < 2) {
        printf("Not enough participants to play :( \n");
        return EXIT_FAILURE;
    }

    fclose(roster);
    roster = fopen("roster.txt", "r");
    char names[lines][50];
    for(int i = 0; i < lines && fgets(names[i], 50, roster) != NULL; i++) {
        names[i][strlen(names[i]) - 1] = '\0';
    }
    fclose(roster);
    for (int i = 0; i < lines; i++) {
        printf("%s\n", names[i]);
    }

    int idxs[lines];
    for(int i = 0; i < lines; i++) idxs[i] = i;
    srandom(95);
    long r = random();
    char snames[lines][50];
    for(int i = lines - 1; i >= 0; i--) {
        int temp = idxs[r % (i + 1)];
        idxs[r % (i + 1)] = idxs[i];
        idxs[i] = temp;
        strcpy(snames[i], names[idxs[i]]);
        r = random();
    }
    char temp[50];
    strcpy(temp, snames[0]);
    for(int i = 1; i < lines; i++)
        strcpy(snames[i - 1], snames[i]);
    strcpy(snames[lines - 1], temp);
    int c;
    initscr();
    do {
        printw("%s", "Type your name: ");
        char input[50];
        getstr(input);
        for(int i = 0; i < lines; i++) {
            if(!strcmp(input, snames[i])) {
                attron(A_BOLD);
                printw("%s\n", names[idxs[i]]);
                attroff(A_BOLD);
                break;
            }
            if(i + 1 == lines)
                printw("%s\n", "You are not on the list");
        }
        printw("\n%s\n", "[PRESS ENTER]");
        c = getch();
        clear();
    } while(c != 'q');
    endwin();
    return EXIT_SUCCESS;
}
