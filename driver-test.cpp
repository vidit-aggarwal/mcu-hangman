//FOR .exe: g++ driver.cpp -lpdcurses -o driver

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

void _initColours();
void mainMenu();
void characterNameGame();
void movieNameGame();
void highScoresDisplay();

class window
{
public:
  WINDOW *win;
  int h, w;
  window()
  {
    win = initscr();
    getmaxyx(win, h, w);
    cbreak();
    noecho();
    start_color();
    _initColours();
  }
  void quit()
  {
              erase();
              mvprintw(h/2, w/2,"Bye!");
              endwin();
              getch();
  }
};


void movieNameGame()
{
  window mGameScreen;
  attron(COLOR_PAIR(WINDOW_COLOUR));
  box(mGameScreen.win, ACS_VLINE, ACS_HLINE );


  //menu
  attron(COLOR_PAIR(SUBTITLE_COLOUR));
  mvprintw(mGameScreen.h/3+2, mGameScreen.w/2-10, "Select a Difficulty:");
  mvprintw(mGameScreen.h/2, mGameScreen.w/2-10, "1. Easy");
  mvprintw(mGameScreen.h/2+1, mGameScreen.w/2-10, "2. Difficult");
  mvprintw(mGameScreen.h/2+2, mGameScreen.w/2-10, "3. Hard");
  mvprintw(mGameScreen.h/2+4, mGameScreen.w/2-10, "Enter '4' for Main Menu and '5' to Exit");
  mvprintw(mGameScreen.h/2+6, mGameScreen.w/2-10, "Enter your choice:");
  ch:
  int choice = getch();
  if(choice>53 || choice<49)
  {
    mvprintw(mGameScreen.h/2+7, mGameScreen.w/2,"Enter a valid number! Retry!");
    move(mGameScreen.h/2+5, mGameScreen.w/2+13);
    goto ch;
  }
  else
  {
    attron(COLOR_PAIR(BLANK));
    mvprintw(mGameScreen.h/2+7, mGameScreen.w/2,"                            ");
    attroff(COLOR_PAIR(BLANK));
    switch(choice)
    {
      case 49:  system("chardiff1.py");
                endwin();
                delwin(mGameScreen.win);
                movieNameGame();
                break;
      case 50:  system("chardiff2.py");
                endwin();
                delwin(mGameScreen.win);
                characterNameGame();
                break;
      case 51:  system("chardiff3.py");
                endwin();
                delwin(mGameScreen.win);
                highScoresDisplay();
                break;
      case 52:  endwin();
                delwin(mGameScreen.win);
                mainMenu();
                break;
      case 53:  mGameScreen.quit();
    }
  }
  attroff(COLOR_PAIR(SUBTITLE_COLOUR));
  attroff(COLOR_PAIR(WINDOW_COLOUR));
}


void characterNameGame()
{
  window cGameScreen;
  attron(COLOR_PAIR(WINDOW_COLOUR));
  box(cGameScreen.win, ACS_VLINE, ACS_HLINE );
  attroff(COLOR_PAIR(WINDOW_COLOUR));
  cGameScreen.quit();
}
void highScoresDisplay()
{
  window score;
  attron(COLOR_PAIR(WINDOW_COLOUR));
  box(score.win, ACS_VLINE, ACS_HLINE );
  attroff(COLOR_PAIR(WINDOW_COLOUR));
  score.quit();
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
  window mywindow;
  attron(COLOR_PAIR(WINDOW_COLOUR));
  box( mywindow.win, ACS_VLINE, ACS_HLINE );
  attron(COLOR_PAIR(TITLE_COLOUR));
  mvprintw(mywindow.h/4+1, mywindow.w/2-12, "<Welcome to MCU Hangman!>");
  attroff(COLOR_PAIR(TITLE_COLOUR));

  //menu
  attron(COLOR_PAIR(SUBTITLE_COLOUR));
  mvprintw(mywindow.h/3+2, mywindow.w/2-10, "Select an Option:");
  mvprintw(mywindow.h/2, mywindow.w/2-10, "1. Start New Game - Movie Names");
  mvprintw(mywindow.h/2+1, mywindow.w/2-10, "2. Start New Game - Character Names");
  mvprintw(mywindow.h/2+2, mywindow.w/2-10, "3. Display High Scores");
  mvprintw(mywindow.h/2+3, mywindow.w/2-10, "4. Exit");
  mvprintw(mywindow.h/2+5, mywindow.w/2-10, "Enter your choice:");
  ch:
  int choice = getch();
  if(choice>52 || choice<49)
  {
    mvprintw(mywindow.h/2+7, mywindow.w/2,"Enter a valid number! Retry!");
    move(mywindow.h/2+5, mywindow.w/2+13);
    goto ch;
  }
  else
  {
    attron(COLOR_PAIR(BLANK));
    mvprintw(mywindow.h/2+7, mywindow.w/2,"                            ");
    attroff(COLOR_PAIR(BLANK));
    switch(choice)
    {
      case 49:  endwin();
                delwin(mywindow.win);
                movieNameGame();
                break;
      case 50:  endwin();
                delwin(mywindow.win);
                characterNameGame();
                break;
      case 51:  endwin();
                delwin(mywindow.win);
                highScoresDisplay();
                break;
      case 52:  mywindow.quit();
    }
  }
  attroff(COLOR_PAIR(SUBTITLE_COLOUR));

  attroff(COLOR_PAIR(WINDOW_COLOUR));
  erase();
  endwin();
}

//main
int main()
{
  mainMenu();
  return 0;
}
