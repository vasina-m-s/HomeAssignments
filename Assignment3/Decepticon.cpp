/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment4
*/

#include "Decepticon.h"
#include <iostream>

//constructor
Decepticon::Decepticon(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun, int evil, int mind):
    Transformer(name, level, health, speed, battle, gun),
    _evil(evil),
    _mind(mind) {};

//methods
bool Decepticon::doEvilPlan()
{
	std::cout << "Decepticon doEvilPlan()\n";
	return true;
}
bool Decepticon::evilLaugh()
{
	std::cout << "Decepticon evilLaugh()\n";
	return true;
}

void Decepticon::transform()
{
    std::cout << "Decepticon transform()\n";
}

void Decepticon::setEvil(int evil) { _evil = evil; }
int Decepticon::getEvil() { return _evil; }

void Decepticon::setMind(int mind) { _mind = mind; }
int Decepticon::getMind() { return _mind; }

std::ostream& operator<<(std::ostream &os, Decepticon &d)
{
    	os << "Decepticon: " << d.getName()
           << " Evil = " << d.getEvil()
           << " Mind = " << d.getMind();
	return os;
}
