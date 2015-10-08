#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include "main.h"
#include "map.h"


int main(void){

	WINDOW * mainwin;
	int windowWidth;
	int windowHeight;
	int response;
	struct screenInfo screenSize = {.w = 0,.h = 0};
	struct gameInfo gameEnv = {.level = 0, .map = {0}};

	setupEverything(mainwin, &screenSize);
	initGame(&gameEnv);

	mvaddstr(screenSize.h - 10, 3, "Press ENTER to play.");
	refresh();

	while (1){
		response = getch();
		if (response == '\n'){
			resetGame(&gameEnv);
			playGame(mainwin, &gameEnv);
			refresh();
			//break;
		}
	}

	cleanupEverything(mainwin);

	return EXIT_SUCCESS;
}

void playGame(WINDOW * mainwin, struct gameInfo * gameEnv){
	int response = 0;


	while (1){
		response = getch();
		//get the key pressed
		//do something with it
		//if key == quit, or do something == end game
		//break;
		refresh();
	}
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
	//generate levels
	//for each level generate a map
	//assign the first map to gameenv
	
	int newMap[MAP_HEIGHT][MAP_WIDTH] = {{0,0}};
	createMap(newMap);
	int x;
	int y;
}
