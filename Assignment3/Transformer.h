/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment3
*/

#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include "Battle.h"
#include "Gun.h"


class Transformer {
	public: //constructor and destructor
        	Transformer(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun);
        	~Transformer();

        	//Methods
        	bool move();
        	bool fire();
        	bool transform();

        	//Getters
        	std::string getName() const;
        	int getLevel();
        	int getHealth();
        	int getSpeed();
        	Gun* getGun();
		Battle getBattle();

        	//Setters
        	void setName(const std::string &name);
        	void setLevel(int level);
        	void setHealth(int health);
        	void setSpeed(int speed);
        	void setGun(Gun* gun);

	private:
        	//Fields
        	std::string _name;
        	int _level;
       		int _health;
        	int _speed;
        	//Composition
        	Battle _battle;
        	//Association
        	Gun* _gun;
};

#endif