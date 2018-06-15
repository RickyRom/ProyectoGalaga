#ifndef PLAYER_H
#define PLAYER_H
#include "ncurses.h"

class player{
    private:
            int xLoc, yLoc, xMax, yMax;
            char character;
            WINDOW * curwin;
            char shot;
            int vida;
    
    
    
    public:
            player(WINDOW * win, int y, int x, char c,int vida);

            void mvleft();
            void mvright();
            int getmv();
            void display();
            void shoot();
            void pintar_corazones();


};
#endif