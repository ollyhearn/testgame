#include <ncurses.h>
#include <stdlib.h>
#include <sstream>
#include <unistd.h>

int main(){

	initscr();
	noecho();
	cbreak();
	//curs_set(0);
	refresh();

	int y, x, yMax, xMax, i, ch, hl=0, enter;
	y = 5;
	x = 7;
	getmaxyx(stdscr, yMax, xMax);
	WINDOW *menu = newwin(y, x, yMax/2, xMax/2);
	box(menu, 0, 0);
	refresh();
	keypad(menu, true);
	wrefresh(menu);
	char choices[3] = {'B', 'H', 'W'};
		move (1,1);
		printw( "%c", choices[1]);
		sleep(5);
	while(1){
	for(i=0; i<3; i++){
		if(i=hl) wattron(menu, A_REVERSE);
		mvwprintw(menu, i+1, 1, "%c", choices[i]);
		wattroff(menu, A_REVERSE);
	}

	ch = wgetch(menu);

	switch(ch){

	case KEY_UP:
		hl--;
		if(hl==-1) hl=2;
	break;

	case KEY_DOWN:
		hl++;
		if(hl==3) hl=0;
	break;

	default:
	break;
	}
	if(ch==10){
		enter=hl;
		break;
		}
	refresh();
	wrefresh(menu);
	}
	endwin();
	return 0;
}
