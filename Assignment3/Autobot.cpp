/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment3
*/

#include "Autobot.h"
#include <iostream>

//constructor
Autobot::Autobot(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun, int bravery, int agility):
    Transformer(name, level, health, speed, battle, gun),
    _bravery(bravery),
    _agility(agility) {};

//methods
bool Autobot::win()
{
	std::cout << "Autobot win()\n";
	return true;
}
bool Autobot::defend()
{
	std::cout << "Autobot defend()\n";
	return true;
}

void Autobot::transform()
{
	std::cout << "Autobot transform()\n";
}

void Autobot::setBravery(int bravery) { _bravery = bravery; }
int Autobot::getBravery() { return _bravery; }

void Autobot::setAgility(int agility) { _agility = agility; }
int Autobot::getAgility() { return _agility; }


std::ostream& operator<<(std::ostream &os, Autobot &a)
{
	os << "Autobot: " << a.getName()
       	   << " bravery=" << a.getBravery()
       	   << " agility=" << a.getAgility();
	return os;
}
