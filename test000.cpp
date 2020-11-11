#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	initscr();
	noecho();
	curs_set(0);
	start_color();
	int h=3, w=10, temp=1;
	WINDOW *win = newwin(h, w, 1, 1);
	refresh();

	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_YELLOW, COLOR_BLUE);
	init_pair(3, COLOR_GREEN, COLOR_MAGENTA);
//	while(h==h){
		while(temp<4){
			move(0,0);
			attron(COLOR_PAIR((int)temp));
			printw("npuBem!");
			sleep(0.5);
			temp++;
		}
		temp=1;
//	}
	getch();
	endwin();
	return 0;
}
