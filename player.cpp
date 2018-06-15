#include "player.h"

player::player(WINDOW * win, int y, int x, char c,int v) {
    
    curwin = win;
    yLoc = y;
    xLoc = x;
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
    character = c;
    vida = v;
}

void player::mvleft() {
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc--;
    if(xLoc < 1) {
        xLoc = 1;
    }
}

void player::mvright() {
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc++;
    if(xLoc >xMax -2) {
        xLoc = xMax - 2;
    }
}

int player::getmv() {
    int choice = wgetch(curwin);
    
    switch (choice){
        case KEY_UP:
            break;
        case KEY_DOWN:
            break;
        case KEY_LEFT:
            mvleft();
            break;
        case KEY_RIGHT:
            mvright();
            break;
        case 32:
            shoot();
            break;
    }
    pintar_corazones();
    return choice;
}

void player::display() {
    mvwaddch(curwin, yLoc, xLoc, character);
}

void player::shoot() {
    for(int i = yLoc -1; i <= 1; i--){
        mvaddch(i, xLoc, '.');
    }
    
}

void player::pintar_corazones() {



    /*int y;// = getcury(curwin);
    int x;// = getcurx(curwin);
    
    getyx(curwin, y, x); printw("Vida: ");
    getyx(curwin, y, x); printw("        ");
    for(int i = 0; i < vida; i++){
        //getyx(curwin,y, x); printf("%c", 3);
        wmove(curwin,y, i+66); 
        refresh(); 
        printw("%c", 3);
    }*/
    
    

}

