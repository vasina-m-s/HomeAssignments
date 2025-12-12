/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment4
*/

#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include <ostream>
#include "Battle.h"
#include "Gun.h"


class Transformer {
	public: //constructor and destructor
        	Transformer(const std::string &name = "unknown", int level = 0, int health = 100, int speed = 1, Battle battle = Battle(), Gun* gun = nullptr);
        	virtual ~Transformer();

        	//Methods
        	virtual bool move();
        	virtual bool fire();
        	virtual void transform() = 0; //purely virtual

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
		friend std::ostream& operator<<(std::ostream &os, Transformer &t);

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