#include <curses.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

struct screenInfo {
	int w;
	int h;
};

struct gameInfo {
	int level;
	int map[MAP_WIDTH][MAP_HEIGHT];
};


void cleanupEverything(WINDOW *mainwin);
void setupEverything(WINDOW *mainwin, struct screenInfo *screenSize);
void playGame(WINDOW *mainwin, struct gameInfo *gameEnv);
void initGame(struct gameInfo *gameEnv);
void resetGame(struct gameInfo *gameEnv);

