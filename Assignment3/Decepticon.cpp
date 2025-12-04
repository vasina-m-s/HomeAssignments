/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment3
*/

#include "Decepticon.h"
#include <iostream>

//constructor
Decepticon::Decepticon(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun, int evil, int mind):
    Transformer(name, level, health, speed, battle, gun),
    _evil(evil),
    _mind(mind) {};

//methods
bool Decepticon::doEvilPlan() { return true; }

void Decepticon::setEvil(int evil) { _evil = evil; }
int Decepticon::getEvil() { return _evil; }

void Decepticon::setMind(int mind) { _mind = mind; }
int Decepticon::getMind() { return _mind; }
