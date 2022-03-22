// TODO undone
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define COLOR false

typedef enum {
	Border,  // entrance or exit
	Wall = '#',
	Path = 'X',
	Taken = 'R',
} Block;

typedef enum {
	East,   // 0deg
	North,  // 90deg
	West,   // 180deg
	South,  // 270deg
} AbsoluteDirection;

typedef enum {
	Front,  // +0deg
	Left,   // +90deg
	Back,   // +180deg
	Right,  // +270deg
} RelativeDirection;

typedef struct {
	AbsoluteDirection direction;
	size_t x, y;
} Solver;

AbsoluteDirection resolve(AbsoluteDirection facing, RelativeDirection to) {
	// Without type casts: return (facing + to) % 4
	return (AbsoluteDirection)(((int)facing + (int)to) % 4);
}

// Check what the block is relative to the solver
Block peek(Solver* self, Block maze[12][12], RelativeDirection rel_dir) {
	// Out-of-bounds check, then return the relative block
	switch (resolve(self->direction, rel_dir)) {
		case East:
			if (self->x == 11) break;
			return maze[self->y][self->x + 1];
		case North:
			if (self->y == 0) break;
			return maze[self->y - 1][self->x];
		case West:
			if (self->x == 0) break;
			return maze[self->y][self->x - 1];
		case South:
			if (self->y == 11) break;
			return maze[self->y + 1][self->x];
	}
	return Border;
}

// Move the solver, changing it's direction and position and mark the path as taken
void move(Solver* self, Block maze[12][12], RelativeDirection rel_dir) {
	self->direction = resolve(self->direction, rel_dir);
	switch (self->direction) {
	case East:
		self->x++;
		break;
	case North:
		self->y--;
		break;
	case West:
		self->x--;
		break;
	case South:
		self->y++;
		break;
	}
	maze[self->y][self->x] = Taken;
}


int main() {
	bool find = false;
	Block maze[12][12];
	Solver solver;

	// get maze from input
	for (size_t row = 0; row < 12; row++) {
		for (size_t col = 0; col < 12;) {
			const char input = getchar();
			if (input != '\n' && input != '\0') {
				maze[row][col] = (Block)input;
				col++;
			}
		}
	}
	// Find the entrance at col 0
	for (size_t row = 0; row < 12; row++) {
		if (maze[row][0] == Path) {
			solver.direction = East;
			solver.x = 0;
			solver.y = row;
			maze[row][0] = Taken;
			break;
		}
	}
	while (true) {
		// Check possible steps in the following order
		const RelativeDirection precedence[] = { Left, Front, Right, Back };
		for (int order = 0; order < 4; order++) {
			const RelativeDirection direction = precedence[order];
			switch (peek(&solver, maze, direction)) {
			case Wall:
				continue;
			case Path:
			case Taken:
				move(&solver, maze, direction);
				goto next_step;
			case Border:
				goto output;
			}
		}
		next_step:;
	}
	output:
	// Output the maze
	for (size_t row = 0; row < 12; row++) {
		for (size_t col = 0; col < 12; col++) {
			#if COLOR
				#define ANSI_COLOR_RED "\x1b[31m"
				#define ANSI_COLOR_GREEN "\x1b[32m"
				#define ANSI_COLOR_YELLOW "\x1b[33m"
				#define ANSI_COLOR_GRAY "\x1b[90m"
				#define ANSI_COLOR_RESET "\x1b[0m"
				switch (maze[row][col]) {
					case Border: 
						fputs(ANSI_COLOR_RED "B" ANSI_COLOR_RESET, stdout);
						break;
					case Wall: 
						fputs(ANSI_COLOR_GRAY "#" ANSI_COLOR_RESET, stdout);
						break;
					case Path: 
						fputs(ANSI_COLOR_GREEN "X" ANSI_COLOR_RESET, stdout); 
						break;
					case Taken: 
						fputs(ANSI_COLOR_YELLOW "R" ANSI_COLOR_RESET, stdout); 
						break;
				}
			#else
				putchar(maze[row][col]);
			#endif
		}
		putchar('\n');
	}
	// check
	for (int index = 0; index < 12; index++) {
		if (maze[index][11] == Taken || maze[index][11] == Border) {
			find = true;
		}
				}
	if (!find) {
		printf("%s", "This maze has no solution\n");
	}
}

/*
############
##XXXXX#XXX#
##X###X###X#
##X#XXXXXXX#
##X#######X#
#XX#X####XX#
XX##XXXXXX##
####X##X##X#
#X#X#XXX##X#
#X#X##X#XXX#
#XXX##XXX#XX
############

*/
