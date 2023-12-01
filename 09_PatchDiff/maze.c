#include <stdio.h>
#include <stdlib.h>

typedef struct cell{ //структура, хранящая координаты клетки в матрице
    unsigned int x;
    unsigned int y;
} cell;

typedef struct cellString{ 
    cell* cells;
    unsigned int size;
} cellString;

void fill_maze(int **maze, int maze_size) {
    for(i = 0; i < maze_size; i++){
        for(j = 0; j < maze_size; j++){
            if((i % 2 != 0  && j % 2 != 0) && (i < height-1 && j < width-1))
                maze[i][j] = '.';
            else maze[i][j] = '#';
        }
    }
}

void free_maze(int **maze, int maze_size) {
    for(i = 0; i < maze_size; i++){
        for(j = 0; j < maze_size; j++){
            free(maze[i][j]);
        }
    }
    
    free(maze);
}


int main(int argc, char **argv) {
    int maze_size = 6;

    int **maze = (int **)malloc(maze_size * size_of(int *));

    for (int i = 0; i < maze_size; ++i) {
        maze[i] = (int *)malloc(maze_size * size_of(int));
    }

    fill_maze(maze, maze_size);


    free_maze();
    return 0;
}