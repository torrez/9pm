#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>                  /*  for sleep()  */
#include <curses.h>
#include "main.h"

int main(void){

	WINDOW * mainwin;

	setupEverything(mainwin);

	playGame(mainwin);

	cleanupEverything(mainwin);

	return EXIT_SUCCESS;
}

void playGame(WINDOW *mainwin){
	mvaddstr(13, 33, "Hello, world!");
	refresh();
	sleep(3);
}

void setupEverything(WINDOW *mainwin){
	/*  Initialize ncurses  */
	if ( (mainwin = initscr()) == NULL ) {
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(EXIT_FAILURE);
	}
}
void cleanupEverything(WINDOW *mainwin){
	delwin(mainwin);
	endwin();
	refresh();
}
