/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment3
*/

#ifndef MAXIMAL_H
#define MAXIMAL_H

#include "Transformer.h"

class Maximal: public Transformer {
    public:
        //constructor
        Maximal(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun, const std::string &animal, int strength);

        //methods
        bool transformBeast();

        //getters
        std::string getAnimal() const;
        int getStrength();

        //setters
        void setAnimal(const std::string &animal);
        void setStrength(int strength);

    private:
        std::string _animal;
        int _strength;
};

#endif