#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <errno.h>
#include <getopt.h>

#define RED "\x1b[1;91m"
#define GREEN "\x1b[3;92m"
#define YELLLOW "\x1b[1;93m"
#define DEFAULT "\x1b[0;0m"

bool is_pos_integer(char *input) {
    if (input[0] == '-') return false;

    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    return true;
}


void display_usage(char *progname) {
    printf("usage: %s [-h] [-f <path>] [-s <seed>] [-l [path]]\n", progname);
    printf("  -f <path>  File to use for list of participants [default: 'roster.txt'].\n");
    printf("  -l [path]  Creates file with list of all pairings [default: 'list.txt'].\n");
    printf("  -s <seed>  Seed to use. Must be a positive integer.\n");
    printf("  -h         Display help.\n");
}

int main(int argc, char *argv[]) {
    if (argc > 8) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    int opt = 0, lflag = 0;
    unsigned int seed = 1;
    char *fpath = NULL, *lpath = NULL, *s_val = NULL;

    while ((opt = getopt(argc, argv, ":l:f:s:h")) != -1) {
        switch (opt) {
            case 'h':
                display_usage(argv[0]);
                return EXIT_SUCCESS;
            case 'l':
                lflag = 1;
                lpath = optarg;
                break;
            case 'f':
                fpath = optarg;
                break;
            case 's':
                s_val = optarg;
                break;
            case '?':
                fprintf(stderr, "%sError:%s Unknown option '-%c' received.\n", RED, DEFAULT, optopt);
                return EXIT_FAILURE;
            default:
                if (optopt == 'l') break;
                fprintf(stderr, "%sError:%s Option '-%c' requires an argument.\n", RED, DEFAULT, optopt);
                return EXIT_FAILURE;
        }
    }

    if (lpath != NULL && lpath[0] == '-') {
        fprintf(stderr, "%sWarning:%s '%s' is an irregular path for list file. [usage ex: 'list.txt'].\n", YELLLOW, DEFAULT, lpath);
    }

    if (s_val != NULL) {
        if (!is_pos_integer(s_val)) {
            fprintf(stderr, "%sError:%s Seed must be a postive integer.\n", RED, DEFAULT);
            return false;
        }
        seed = (unsigned int)atoi(s_val);
    }

    if (optind < argc) {
        fprintf(stderr, "%sError:%s Too many arguments have been supplied or incorrect format.\n       Use '-h' to check usage.\n", RED, DEFAULT);
        return EXIT_FAILURE;
    }

    if (lflag) {
        printf("%sList functionality is not currently implemented.%s\n", GREEN, DEFAULT);
        return EXIT_SUCCESS;
    }

    FILE *roster;
    if (fpath == NULL) fpath = "roster.txt";
    if ((roster = fopen(fpath, "r")) == NULL) {
        fprintf(stderr, "%sError:%s Could not open '%s'. %s.\n", fpath, RED, DEFAULT, strerror(errno));
        return EXIT_FAILURE;
    }

    int lines = 0;
    char buf[256];
    while(fgets(buf, sizeof(buf), roster) != NULL) {
        lines++;
    }
    buf[strcspn(buf, "\n")] = 0;
    if (lines < 2) {
        fprintf(stderr, "%sError:%s Not enough participants to play.\n", RED, DEFAULT);
        return EXIT_FAILURE;
    }

    fclose(roster);

    if ((roster = fopen(fpath, "r")) == NULL) {
        fprintf(stderr, "%sError:%s Could not open '%s'. %s.\n", fpath, RED, DEFAULT, strerror(errno));
        return EXIT_FAILURE;
    }
    char names[lines][50];
    for(int i = 0; i < lines && fgets(names[i], 50, roster) != NULL; i++) {
        names[i][strlen(names[i]) - 1] = '\0';
    }
    fclose(roster);

    int idxs[lines];
    for(int i = 0; i < lines; i++) idxs[i] = i;
    srandom(seed);
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

    printf("%ssecret-santa closed.%s\n", GREEN, DEFAULT);

    return EXIT_SUCCESS;
}
