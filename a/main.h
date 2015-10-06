
struct screenInfo {
	int w;
	int h;
};

struct gameInfo {
	int level;
};


void cleanupEverything(WINDOW *mainwin);
void setupEverything(WINDOW *mainwin, struct screenInfo *screenSize);
void playGame(WINDOW *mainwin, struct gameInfo *gameEnv);
void initGame(struct gameInfo *gameEnv);
void resetGame(struct gameInfo *gameEnv);

