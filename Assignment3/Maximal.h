/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment4
*/

#ifndef MAXIMAL_H
#define MAXIMAL_H

#include "Transformer.h"

class Maximal: public Transformer {
    public:
        //constructor
        Maximal(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun, const std::string &animal, int strength);
	Maximal(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun, const std::string &animal);
	Maximal(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun);
	Maximal(const std::string &name, int level, int health, int speed, Battle battle);
	Maximal(const std::string &name, int level, int health, int speed);
	Maximal(const std::string &name, int level, int health);
	Maximal(const std::string &name, int level);
	Maximal(const std::string &name);

        //methods
        virtual bool transformBeast();
	bool move() override;
    	void transform() override;

        //getters
        std::string getAnimal() const;
        int getStrength();

        //setters
        void setAnimal(const std::string &animal);
        void setStrength(int strength);

	friend std::ostream& operator<<(std::ostream &os, Maximal &m);

    private:
        std::string _animal;
        int _strength;
};

#endif