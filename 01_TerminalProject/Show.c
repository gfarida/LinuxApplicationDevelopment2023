#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>


#define DX 2
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

void read_all_file(char *all_file, FILE *file, int *size, int *num_of_lines) {
    int c;
    for (int i = 0; i < *size; ++i) {
        c = fgetc(file);
        if (c == '\n') {
            (*num_of_lines)++;
        }
        all_file[i] = c;
    }
    all_file[*size] = '\n';
    all_file[*size + 1] = '\0';
    (*num_of_lines)++;
    fclose(file);
}

void cut_file_to_lines(char *all_file, 
                       char **file_in_lines, 
                       int *size, 
                       int *num_of_lines) {
    int cur_line = 0, vol = 1, j = 0, i = 0;
    while (all_file[i] != '\0') {

        if (vol == 1) {
            file_in_lines[cur_line] = (char *)malloc((vol + 1) * sizeof(char));
        }

        if (j == (vol - 1)) {
            vol = 2 * vol + 1;
            file_in_lines[cur_line] = (char *)realloc(file_in_lines[cur_line], (vol+1)*sizeof(char));  
        }

        if (all_file[i] != '\n') {
            file_in_lines[cur_line][j] = all_file[i];
            j++;
        } else {
            file_in_lines[cur_line][j] = '\0';
            cur_line++;
            vol = 1;
            j = 0;
        }
        i++;
    }
}


int main(int argc, char **argv) {
    char *all_file;
    char **file_in_lines;
    int num_of_lines = 0, cur_line = 0, cur_col = 0, c = 0, delta = cur_line;
    WINDOW *win;

    setlocale(LC_ALL, "");
    FILE *file;
    struct stat info;
    int file_size;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename!\n", argv[0]);
        return -1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Can't open file %s!\n", argv[1]);
        return -1;
    }

    stat(argv[1], &info);
    file_size = info.st_size;
    all_file = (char *)malloc((file_size + 2) * sizeof(char));


    if (all_file == NULL) {
        fprintf(stderr, "Can't allocate memory!\n");
        return -1;
    }

    initscr();
    noecho();
    cbreak();
    printw("FILENAME: %s \n", argv[1]);
    refresh();

    win = newwin(LINES - 2*DX, COLS - 2*DX, DX, DX);
    int win_size = LINES - 2*DX;
    keypad(win, TRUE);
    scrollok(win, TRUE);
    
    
    read_all_file(all_file, file, &file_size, &num_of_lines);
    file_in_lines = (char **)malloc((num_of_lines + 1) * sizeof(char *));
    cut_file_to_lines(all_file, file_in_lines, &file_size, &num_of_lines);
    
    box(win, 0, 0);
    c = 1;
    while(c != 27) {
        werase(win);
        for (int i = 0; i < win_size; ++i) {
            if (cur_line + i >= num_of_lines) {
                break;
            }
            mvwprintw(win, i + 2, 1, "%d \t %s\n", cur_line + i, 
                      MIN(cur_col, strlen(file_in_lines[i + cur_line])) 
                      + file_in_lines[i + cur_line]);
        }

        box(win, 0, 0);
        wrefresh(win);

        c = wgetch(win);
        
        switch(c) {
            case KEY_DOWN: {
                if (cur_line + win_size < num_of_lines) {
                    cur_line++;
                }
                break;
            }
            case KEY_UP: {
                if (cur_line > 0) {
                    cur_line --;
                }
                break;
            }
            case KEY_RIGHT: {
                cur_col++;
                break;
            }
            case KEY_LEFT: {
                if (cur_col > 0) {
                    cur_col--;
                }   
                break;
            }
            case KEY_NPAGE: {
                cur_line += win_size - DX;
                cur_line = MIN(num_of_lines - win_size, cur_line);

                break;
            }
            case KEY_PPAGE: {
                if (cur_line > win_size) {
                    cur_line -= win_size + DX;
                } else {
                    cur_line = 0;
                }
                break;
            }
        }

        
    }

    for (int i = 0; i < num_of_lines; ++i) {
        free(file_in_lines[i]);
    }
    free(file_in_lines);
    free(all_file);
    
    endwin();
    return 0;
} 