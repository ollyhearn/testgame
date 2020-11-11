#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	initscr();
	noecho();
	curs_set(0);
  refresh();
  system("clear");


  int yMax, xMax;
  int c;
  bool correctAnswer=false;
  getmaxyx(stdscr, yMax, xMax);
  int y=3, x=15;
  WINDOW *pipka = newwin(y, x, yMax/2-5, xMax/2-10);
  WINDOW *ans = newwin(y, 5, yMax/2-2, xMax/2-5);
  WINDOW *repl = newwin(y, 15, yMax/2+1, xMax/2-2);
  WINDOW *sad = newwin(y, 4, yMax/2+1, xMax/2-2);
  WINDOW *what = newwin(y, 4, yMax/2+1, xMax/2-2);
  box(pipka, 0, 0);
  box(ans, 0, 0);
  keypad(ans, true);
  mvwprintw(pipka, 1, 1, "npuBem? [y/n]");
  refresh();
  wrefresh(pipka);
  wmove(ans, 1, 1);
  wrefresh(ans);
  c = wgetch(ans);
  if (c == 'y'){
    box(repl, 0, 0);
    mvwprintw(repl, 1, 1, "npuBeeeem :D");
    wrefresh(repl);
    correctAnswer=true;
  }
  if (c == 'n'){
    box(sad, 0, 0);
    mvwprintw(sad, 1, 1, ":(");
    wrefresh(sad);
    correctAnswer=true;
  }
  if (correctAnswer==false){
    box(what, 0, 0);
    mvwprintw(what, 1, 1, "??");
    wrefresh(what);
  }
  getch();
  endwin();
  return 0;
}
