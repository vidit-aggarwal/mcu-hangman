//Importing Necessary Header Files
#include <iostream>
#include "conio.h"
#include "curses.h"
#include <string.h>
#define WINDOW_COLOUR 1
#define TITLE_COLOUR 2
#define SUBTITLE_COLOUR 3
#define TEXT_COLOUR 4
#define BLANK 5
using namespace std;

void movieNameGame()
{
  //TODO
}
void characterNameGame()
{
  //TODO
}
void highScoresDisplay()
{
  //TODO
}

//_initColours: To initialise different color combinations of the window
void _initColours()
{
  /*
  Colours Available
  COLOR_BLACK
  COLOR_RED
  COLOR_GREEN
  COLOR_YELLOW
  COLOR_BLUE
  COLOR_MAGENTA
  COLOR_CYAN
  COLOR_WHITE
  */
  init_pair(WINDOW_COLOUR, COLOR_WHITE, COLOR_MAGENTA);
  init_pair(TITLE_COLOUR, COLOR_YELLOW, COLOR_MAGENTA);
  init_pair(SUBTITLE_COLOUR, COLOR_BLUE, COLOR_WHITE);
  init_pair(TEXT_COLOUR, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(BLANK, COLOR_BLACK, COLOR_BLACK);

}

//mainMenu: This function runs the main window of the Program
void mainMenu()
{
  int h, w;
  WINDOW *mywindow;
  mywindow = initscr();
  cbreak();
  noecho();
  start_color();
  _initColours();
  attron(COLOR_PAIR(WINDOW_COLOUR));
  getmaxyx(mywindow, h, w);
  box( mywindow, ACS_VLINE, ACS_HLINE );
  attron(COLOR_PAIR(TITLE_COLOUR));
  mvprintw(h/4+1, w/2-12, "<Welcome to MCU Hangman!>");
  attroff(COLOR_PAIR(TITLE_COLOUR));

  //menu
  attron(COLOR_PAIR(SUBTITLE_COLOUR));
  mvprintw(h/3+2, w/2-10, "Select an Option:");
  mvprintw(h/2, w/2-10, "1. Start New Game - Movie Names");
  mvprintw(h/2+1, w/2-10, "2. Start New Game - Character Names");
  mvprintw(h/2+2, w/2-10, "3. Display High Scores");
  mvprintw(h/2+3, w/2-10, "4. Exit");
  mvprintw(h/2+5, w/2-10, "Enter your choice:");
  ch:
  int choice = getch();
  if(choice>52 || choice<49)
  {
    mvprintw(h/2+7, w/2,"Enter a valid number! Retry!");
    move(h/2+5, w/2+13);
    goto ch;
  }
  else
  {
    attron(COLOR_PAIR(BLANK));
    mvprintw(h/2+7, w/2,"                            ");
    attroff(COLOR_PAIR(BLANK));
    switch(choice)
    {
      case 49:  erase();
                endwin();
                movieNameGame();
                break;
      case 50:  characterNameGame();
                break;
      case 51:  highScoresDisplay();
                break;
      case 52:  erase();
                mvprintw(h/2,w/2,"Bye!");
                endwin();
                getch();
                break;
    }
  }
  attroff(COLOR_PAIR(SUBTITLE_COLOUR));

  attroff(COLOR_PAIR(WINDOW_COLOUR));
  getch();
  erase();
  endwin();
}

//main
int main()
{
  mainMenu();
  return 0;
}
