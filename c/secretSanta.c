#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>


int main(int argc, char const *argv[]) {
    FILE *fnames = fopen("roster.txt", "r");
    int lines = 0;
    char s[50];
    while(!feof(fnames)) {
        fgets(s, 50, fnames);
        lines++;
    }
    fclose(fnames);
    fnames = fopen("roster.txt", "r");
    char names[lines][50];
    for(int i = 0; i < lines; i++) {
        fgets(names[i], 50, fnames);
        if(i != lines - 1)
            names[i][strlen(names[i]) - 1] = '\0';
    }
    fclose(fnames);
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
    return 0;
}
