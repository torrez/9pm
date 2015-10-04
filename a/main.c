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
	screenTuple screenSize;
	gameTuple gameEnv;

	screenSize = setupEverything(mainwin);
	gameEnv = initGame();

	mvaddstr(screenSize.h - 10, 3, "Press ENTER to play.");
	refresh();

	while (1){
		response = getch();
		if (response == '\n'){
			//resetGame(gameStats);
			playGame(mainwin, gameEnv);
			mvaddstr(10,10, "boom!");
			refresh();
			//break;
		}
	}

	cleanupEverything(mainwin);

	return EXIT_SUCCESS;
}

void playGame(WINDOW *mainwin, gameTuple gameEnv){

	
	//drawMap(10,10);

	char buf[100];
	sprintf(buf, "Hello, world %d.", gameEnv.level);
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

screenTuple setupEverything(WINDOW *mainwin){
	int screenWidth;
	int screenHeight;
	screenTuple screenSize;

	if ( (mainwin = initscr()) == NULL ) {
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(EXIT_FAILURE);
	}
	curs_set(0);
	noecho();
	screenSize.w = getmaxx(mainwin);
	screenSize.h = getmaxy(mainwin);
	return screenSize;
}

void cleanupEverything(WINDOW *mainwin){
	delwin(mainwin);
	endwin();
	refresh();
}

gameTuple initGame(){
	gameTuple gt;

	gt.level = 1;
	return gt;
}
