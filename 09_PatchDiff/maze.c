#include <stdio.h>
#include <stdlib.h>

//алгоритм взят с сайта: https://habr.com/ru/articles/262345/

enum cellTypes {CELL = 0, GENCELL, GENVISITED, RENDERED, WALL, WAY, CURRENT, LAST, SEEKED, EXIT};

struct cell {
    int x;
    int y;
} cell;

struct cellString { 
    struct cell* cells;
    int size;
} cellString;

struct stack { 
    struct cell cell;
    struct stack next;
    int size;
} stack;

void fill_maze(int **maze, int maze_size) {
    for (i = 0; i < maze_size; i++) {
        for (j = 0; j < maze_size; j++) {
            if ((i % 2 != 0  && j % 2 != 0) && (i < maze_size - 1 && j < maze_size - 1)) {
                maze[i][j] = '.';
            } else {
                maze[i][j] = '#';
            }
        }
    }
}

void print_maze(int **maze, int maze_size) {
    for (i = 0; i < maze_size; i++) {
        for (j = 0; j < maze_size; j++) {
            if (maze[i][j] == WALL) {
                printf("#");
            } else {
                printf(".");
            } 
        }
        printf("\n");
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

struct cellString get_neighbours(int maze_size, int** maze, cell c){
    int i, x = c.x, y = c.y;

    cell up = {x, y - 2}, rt = {x + 2, y}, dw = {x, y + 2}, lt = {x - 2, y};
    cell d[4]  = {dw, rt, up, lt};
    int size = 0;

    struct cellString cells;
    cells.cells = malloc(4 * sizeof(cell));

    for (i = 0; i < 4; i++){
        if (d[i].x > 0 && d[i].x < maze_size && d[i].y > 0 && d[i].y < maze_size) {
            int maze_cur_cell = maze[d[i].y][d[i].x];
            cell cur_cell = d[i];
            if (maze_cur_cell != WALL && maze_cur_cell != VISITED){
                cells.cells[size] = cur_cell;
                ++size;
            }
        }
    }
    cells.size = size;
    return cells;
}


int **remove_wall(struct cell first, struct cell second, int **maze) {
    int xDiff = second.x - first.x;
    int yDiff = second.y - first.y;
    int addX, addY;
    struct cell target;

    addX = (xDiff != 0) ? (xDiff / abs(xDiff)) : 0;
    addY = (yDiff != 0) ? (yDiff / abs(yDiff)) : 0;

    target.x = first.x + addX;
    target.y = first.y + addY;

    maze[target.y][target.x] = VISITED;
    return maze;
}

int **set_mode(struct cell c, int **maze, int mode){
    int x = c.x;
    int y = c.y;
    maze[y][x] = mode;
    return maze;
}

void push(struct stack **s, struct cell c, int* sizeptr){
   stack *tmp = malloc(sizeof(stack));
   tmp->next = *s;
   tmp->c = c;
   (*sizeptr)++;
   *s = tmp;
}

cell pop(struct stack **s, int* sizeptr){
    stack* out;
    cell c;
    out = *s;
    *s = (*s)->next;
    c = out->c;
    (*sizeptr)--;
    free(out);
    return c;
}

int unvisited_count(int **maze, int maze_size) {
    int res = 0;
    for(i = 0; i < maze_size; i++){
        for(j = 0; j < maze_size; j++){
            if (maze[i][j] != VISITED && maze[i][j] != WALL) {
                ++res;
            }
        }
    }
    return res;
}


int main(int argc, char **argv) {
    int maze_size = 6;

    int **maze = (int **)malloc(maze_size * size_of(int *));

    for (int i = 0; i < maze_size; ++i) {
        maze[i] = (int *)malloc(maze_size * size_of(int));
    }

    fill_maze(maze, maze_size);

    struct cell start_cell = {1, 1}, cur_cell = {1, 1}, neighbour_cell = {1, 1};
    struct stack *stack_of_cells;
    int stack_size = 0;

    cur_cell = start_cell;
    do{
        struct cellString neighbours = get_neighbours(maze_size, maze, cur_cell);
        if (neighbours.size != 0) {
            int random_idx = rand() % (neighbours.size);
            neighbour_cell = neighbours.cells[random_idx]; 

            push(&stack_of_cells, cur_cell, &stack_size);

            maze = remove_wall(cur_cell, neighbour_cell, maze); 
            cur_cell = neighbour_cell; 
            maze = set_mode(cur_cell, maze, VISITED);

            free(neighbours.cells);
        } else if (stack_size > 0){
            cur_cell = pop(&stack_of_cells, &stack_size);
        }
    } while (unvisited_count(maze, maze_size) > 0);

    print_maze(maze, maze_size;)
    free_maze(maze, maze_size);
    return 0;
}