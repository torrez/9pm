#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include "main.h"

int main(void){

	WINDOW * mainwin;
	int windowWidth;
	int windowHeight;
	int response;
	struct screenInfo screenSize = {0,0};
	struct gameInfo gameEnv = {0};

	setupEverything(mainwin, &screenSize);
	initGame(&gameEnv);

	printf("About to call screenSize->h\n\n");
	mvaddstr(screenSize.h - 10, 3, "Press ENTER to play.");
	refresh();

	while (1){
		response = getch();
		if (response == '\n'){
			resetGame(&gameEnv);
			playGame(mainwin, &gameEnv);
			mvaddstr(10,10, "boom!");
			refresh();
			//break;
		}
	}

	cleanupEverything(mainwin);

	return EXIT_SUCCESS;
}

void playGame(WINDOW * mainwin, struct gameInfo * gameEnv){

	//drawMap(10,10);

	char buf[100];
	sprintf(buf, "Hello, world %d.", gameEnv->level);
	mvaddstr(13, 33, buf);
	//while (1){
		//get the key pressed
		//do something with it
		//if key == quit, or do something == end game
		//break;
		refresh();
	//}
	sleep(3);
}

void setupEverything(WINDOW *mainwin, struct screenInfo *screenSize){
	if ( (mainwin = initscr()) == NULL ) {
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(EXIT_FAILURE);
	}
	curs_set(0);
	noecho();
	screenSize->w = getmaxx(mainwin);
	screenSize->h = getmaxy(mainwin);
}

void cleanupEverything(WINDOW *mainwin){
	delwin(mainwin);
	endwin();
	refresh();
}

void initGame(struct gameInfo *gameEnv){
	gameEnv->level = 1;
}

void resetGame(struct gameInfo *gameEnv){
	gameEnv->level = 1;
}
