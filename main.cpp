#include <ncurses.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "player.h"
#include "unistd.h"

using namespace std;

void drawBorders(WINDOW *);

int main(int argc, char *argv[]){

    int parent_x;
    int parent_y;
    int new_y;
    int new_x;
    int score_size = 3;

    initscr();
    noecho();
    curs_set(FALSE);
    getmaxyx(stdscr, parent_y, parent_x);
    WINDOW * field = newwin(parent_y - score_size, parent_x, 0, 0);
    WINDOW * score = newwin(score_size, parent_x, parent_y - score_size, 0);

    drawBorders(field);
    drawBorders(score);
    while(1) {
        getmaxyx(stdscr, new_y, new_x);
        if(new_y != parent_y || new_x != parent_x) {
            parent_x = new_x;
            parent_y = new_y;
            wresize(field, new_y - score_size, new_x);
            mvwin(score, new_y - score_size, 0);
            wclear(stdscr);
            wclear(field);
            wclear(score);
            drawBorders(field);
            drawBorders(score);
        }

        mvwprintw(field, 0, 0, "Galaga Infinity War");
        mvwprintw(score, 1, 1, "Score:");
        mvwprintw(score, 1, 20,"Vidas:");
        wrefresh(field);
        wrefresh(score);
    }

    player * p = new player(field, parent_y, parent_x / 2, '@',3);
     do{
        p -> display();
        wrefresh(field);

    }while(p -> getmv() != 'x');


    sleep(5);
    delwin(field);
    delwin(score);
    endwin();
    return 0;



















    /*empieza ncurses
    initscr();
    noecho();
    cbreak();

    //tamaño de pantalla
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    //crear una ventana para el programa
    WINDOW * playwin = newwin(30, 80, (yMax/2) - 15, 15);
    box(playwin, 0, 0);
    refresh();
    wrefresh(playwin);

    player * p = new player(playwin, 28, 40, '@',3);
     do{
        p -> display();
        wrefresh(playwin);

    }while(p -> getmv() != 'x');

    //esperar que el programa espere mientras cierra
    getch();
    endwin();
    //termina ncurses*/

}

void drawBorders(WINDOW * screen) {
    int x, y, i;
    getmaxyx(screen, y, x);
    mvwprintw(screen,0,0,"+");
    mvwprintw(screen,y-1,0,"+");
    mvwprintw(screen, 0, x - 1, "+");
    mvwprintw(screen, y - 1, x - 1, "+");
    for(int i = 1; i < (y-1); i++){
        mvwprintw(screen, i, 0, "|");
        mvwprintw(screen, i, x - 1, "|");
    }

    for(int i = 1; i < (x-1); i++) {
        mvwprintw(screen, 0, i, "-");
        mvwprintw(screen, y - 1, i, "-");
    }
    
}
