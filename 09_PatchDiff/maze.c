#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
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

void print_maze(int **maze, int maze_size) {
    for(i = 0; i < maze_size; i++){
        for(j = 0; j < maze_size; j++){
            if((i % 2 != 0  && j % 2 != 0) && (i < height-1 && j < width-1))
                printf(".");
            else 
                printf("#");
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

cellString get_neighbours(int maze_size, int** maze, cell c){
    unsigned int i;
    unsigned int x = c.x;
    unsigned int y = c.y;

    cell up = {x, y - 2};
    cell rt = {x + 2, y};
    cell dw = {x, y + 2};
    cell lt = {x - 2, y};
    cell d[4]  = {dw, rt, up, lt};
    unsigned int size = 0;

    cellString cells;
    cells.cells = malloc(4 * sizeof(cell));

    for(i = 0; i < 4; i++){ //для каждого направдения
        if(d[i].x > 0 && d[i].x < width && d[i].y > 0 && d[i].y < height){ //если не выходит за границы лабиринта
            unsigned int mazeCellCurrent = maze[d[i].y][d[i].x];
            cell     cellCurrent     = d[i];
            if(mazeCellCurrent != WALL && mazeCellCurrent != VISITED){ //и не посещена\является стеной
                cells.cells[size] = cellCurrent; //записать в массив;
                size++;
            }
        }
    }
    cells.size = size;
    return cells;


int main(int argc, char **argv) {
    int maze_size = 6;

    int **maze = (int **)malloc(maze_size * size_of(int *));

    for (int i = 0; i < maze_size; ++i) {
        maze[i] = (int *)malloc(maze_size * size_of(int));
    }

    fill_maze(maze, maze_size);

    cell startCell = {1, 1}
    cell currentCell = startCell;
    cell neighbourCell;
    do{
        cellString Neighbours = get_neighbours(width, height, maze, startPoint, 2);
        if(Neighbours.size != 0){ //если у клетки есть непосещенные соседи
            randNum  = random(0, Neighbours.size-1);
            neighbourCell = cellStringNeighbours.cells[randNum]; //выбираем случайного соседа
            push(d.startPoint); //заносим текущую точку в стек
            maze = remove_wall(currentCell, neighbourCell, maze); //убираем стену между текущей и сосендней точками
            currentCell = neighbourCell; //делаем соседнюю точку текущей и отмечаем ее посещенной
            maze = set_mode(d.startPoint, d.maze, VISITED);
            free(cellStringNeighbours.cells);
        }
        else if(stackSize > 0){ //если нет соседей, возвращаемся на предыдущую точку
            startPoint = pop();
        }
        else{ //если нет соседей и точек в стеке, но не все точки посещены, выбираем случайную из непосещенных
            cellString cellStringUnvisited = get_unvisister_cells(width, height, maze);
            randNum = random(0, cellStringUnvisited.size-1);
            currentCell = cellStringUnvisited.cells[randNum];
            free(cellStringUnvisited.cells);
        }

    
    while(unvisitedCount() > 0);git stats

    print_maze(maze, maze_size;)
    free_maze();
    return 0;
}