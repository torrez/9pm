
typedef struct {
	int w;
	int h;
} screenTuple;

typedef struct {
	int level;
} gameTuple;

void cleanupEverything(WINDOW *mainwin);
screenTuple setupEverything(WINDOW *mainwin);
void playGame(WINDOW *mainwin, gameTuple gameEnv);
gameTuple initGame();

