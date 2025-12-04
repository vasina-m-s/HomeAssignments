/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment3
*/

#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "Transformer.h"

class Autobot: public Transformer {
    public:
        //constructor
        Autobot(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun, int bravery, int agility);

        //methods
        bool win();

        //getters
        int getBravery();
        int getAgility();

        //setters
        void setBravery(int bravery);
        void setAgility(int agility);

    private:
        int _bravery;
        int _agility;
};

#endif