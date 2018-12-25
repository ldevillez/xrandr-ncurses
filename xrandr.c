#include <ncurses.h>
#include <stdlib.h>
WINDOW *menu_win, *left, *top, *right, *bottom, *center;
void drawLeft(int a);
void drawRight(int a);
void drawTop(int a);
void drawBottom(int a);
void drawCenter(int a);

#define WIDTH 80
#define HEIGHT 24

int startx = 0;
int starty = 0;
int main()
{

  int ch = 0;
  int state = 0;

  startx = WIDTH / 3;
	starty = HEIGHT / 3;


	initscr();			/* Start curses mode 		*/
  noecho();
  cbreak();
  left = newwin(starty,startx,starty,0);
  top = newwin(starty,startx,0,startx);
  right = newwin(starty,startx,starty,2*startx);
  bottom = newwin(starty,startx,2*starty,startx);
  center = newwin(starty,startx,starty,startx);


  refresh();
  drawLeft(0);
  drawRight(0);
  drawTop(0);
  drawBottom(0);
  drawCenter(0);

  keypad(stdscr, TRUE);
  while( ch != '\n'){
    switch(ch){
      case KEY_UP:
        switch(state){
          case 0:
            state = 10;
          break;
          case 1:
            state = 10;
          break;
          case -1:
            state = 10;
          break;
          case -10:
            state = 0;
          break;
        }
      break;
      case KEY_DOWN:
      switch(state){
        case 0:
          state = -10;
        break;
        case 1:
          state = -10;
        break;
        case -1:
          state = -10;
        break;
        case 10:
          state = 0;
        break;
      }
      break;
      case KEY_RIGHT:
      switch(state){
        case 0:
          state = 1;
        break;
        case 10:
          state = 1;
        break;
        case -10:
          state = 1;
        break;
        case -1:
          state = 0;
        break;
      }
      break;
      case KEY_LEFT:
      switch(state){
        case 10:
          state = -1;
        break;
        case -10:
          state = -1;
        break;
        case 0:
          state = -1;
        break;
        case 1:
          state = 0;
        break;
      }
      break;
    }
    switch (state) {
      case 0:
        drawTop(0);
        drawRight(0);
        drawCenter(1);
        drawLeft(0);
        drawBottom(0);
        break;

      case 1:
        drawTop(0);
        drawRight(1);
        drawCenter(0);
        drawLeft(0);
        drawBottom(0);
        break;

      case 10:
        drawTop(1);
        drawRight(0);
        drawCenter(0);
        drawLeft(0);
        drawBottom(0);
        break;

      case -1:
        drawTop(0);
        drawRight(0);
        drawCenter(0);
        drawLeft(1);
        drawBottom(0);
        break;

      case -10:
        drawTop(0);
        drawRight(0);
        drawCenter(0);
        drawLeft(0);
        drawBottom(1);
        break;

    }
    curs_set(0);
    ch = getch();
  }
	endwin();			/* End curses mode		  */

  switch (state) {
    case 0:
      system("xrandr --output eDP-1 --auto");
      system("xrandr --output HDMI-2  --off");
      system("nohup /home/westornd/.config/polybar/i3wmthemer_bar_launch.sh");
      system("nohup nitrogen --restore");
      break;

    case 1:
      system("xrandr --output eDP-1 --auto");
      system("xrandr --output HDMI-2  --auto --right-of eDP-1");
      system("nohup /home/westornd/.config/polybar/i3wmthemer_bar_launch.sh");
      system("nohup nitrogen --restore");
      break;

    case 10:
      system("xrandr --output eDP-1 --auto");
      system("xrandr --output HDMI-2  --auto --same-as eDP-1");
      system("nohup /home/westornd/.config/polybar/i3wmthemer_bar_launch.sh");
      system("nohup nitrogen --restore");
      break;

    case -1:
      system("xrandr --output eDP-1 --auto");
      system("xrandr --output HDMI-2  --auto --left-of eDP-1");
      system("nohup /home/westornd/.config/polybar/i3wmthemer_bar_launch.sh");
      system("nohup nitrogen --restore");
      break;

    case -10:
      system("xrandr --output eDP-1  --off");
      system("xrandr --output HDMI-2  --auto");
      system("nohup /home/westornd/.config/polybar/i3wmthemer_bar_launch.sh");
      system("nohup nitrogen --restore");
      break;

  }

	return 0;
}

void drawLeft(int a){
  box(left,0,0);
  if(a == 1){
    wattron(left,A_REVERSE);
  }
  mvwprintw(left,4,7,"HDMI  LAPTOP");
  wrefresh(left);
  if(a == 1){
    wattroff(left,A_REVERSE);
  }
}

void drawRight(int a){
  box(right,0,0);
  if(a == 1){
    wattron(right,A_REVERSE);
  }
  mvwprintw(right,4,7,"LAPTOP  HDMI");
  wrefresh(right);
  if(a == 1){
    wattroff(right,A_REVERSE);
  }
}

void drawTop(int a){
  box(top,0,0);
  if(a == 1){
    wattron(top,A_REVERSE);
  }
  mvwprintw(top,3,11,"HDMI");
  mvwprintw(top,4,10,"LAPTOP");
  wrefresh(top);
  if(a == 1){
    wattroff(top,A_REVERSE);
  }
}

void drawBottom(int a){
  box(bottom,0,0);
  if(a == 1){
    wattron(bottom,A_REVERSE);
  }
  mvwprintw(bottom,4,11,"HDMI");
  wrefresh(bottom);
  if(a == 1){
    wattroff(bottom,A_REVERSE);
  }
}

void drawCenter(int a){
  box(center,0,0);
  if(a == 1){
    wattron(center,A_REVERSE);
  }
  mvwprintw(center,4,10,"LAPTOP");
  wrefresh(center);
  if(a == 1){
    wattroff(center,A_REVERSE);
  }
}
