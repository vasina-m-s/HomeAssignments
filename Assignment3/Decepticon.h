/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment3
*/

#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "Transformer.h"

class Decepticon: public Transformer {
    public:
        //constructor
        Decepticon(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun, int evil, int mind);

        //methods
        bool doEvilPlan();

        //getters
        int getEvil();
        int getMind();

        //setters
        void setEvil(int evil);
        void setMind(int mind);

    private:
        int _evil;
        int _mind;
};

#endif