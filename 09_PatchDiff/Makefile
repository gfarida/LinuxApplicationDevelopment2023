TRASH = *.o maze maze_patch_1.c maze_patch_2.c maze_patch_3.c maze_patch_1 maze_patch_2 maze_patch_3 maze.c.orig maze_1 maze_2 maze_3

all:	maze maze_1 maze_2 maze_3

maze:	maze.c
		cc $< -o $@

maze_1: maze.c patch_1
		patch -b maze.c patch_1
		mv maze.c maze_patch_1.c
		mv maze.c.orig maze.c
		cc maze_patch_1.c -o maze_1

maze_2: maze.c patch_2
		patch -b maze.c patch_2
		mv maze.c maze_patch_2.c
		mv maze.c.orig maze.c
		cc maze_patch_2.c -o maze_2

maze_3: maze.c patch_3
		patch -b maze.c patch_3
		mv maze.c maze_patch_3.c
		mv maze.c.orig maze.c
		cc maze_patch_3.c -o maze_3

run:	all
		./maze
		./maze_1 9
		./maze_2 .@ 9
		./maze_3 13 .@ 9
		./maze_3 13 .@ 9

clean:
		rm -f $(TRASH)