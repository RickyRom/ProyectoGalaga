#ifndef PUNTAJE_H
#define PUNTAJE_H
#include <string>
using std::string;

class puntaje {
    private:
            string score;
            int cantidad;
    public:
            puntaje();
            puntaje(string,int);

            //getters
            string getScore();
            int getCantidad();

            //setters
            void setScore(string);
            void setCantidad(int);
};
#endif