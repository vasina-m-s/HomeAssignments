/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment4
*/

#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "Transformer.h"

class Autobot: public Transformer {
    public:
        //constructor
        Autobot(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun, int bravery, int agility);
	Autobot(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun, int bravery);
	Autobot(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun);
	Autobot(const std::string &name, int level, int health, int speed, Battle battle);
	Autobot(const std::string &name, int level, int health, int speed);
	Autobot(const std::string &name, int level, int health);
	Autobot(const std::string &name, int level);
	Autobot(const std::string &name);

        //methods
        virtual bool win();
    	virtual bool defend();
	void transform() override;

        //getters
        int getBravery();
        int getAgility();

        //setters
        void setBravery(int bravery);
        void setAgility(int agility);
	
	friend std::ostream& operator<<(std::ostream &os, Autobot &a);

    private:
        int _bravery;
        int _agility;
};

#endif