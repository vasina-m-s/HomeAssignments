/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment3
*/

#include "Maximal.h"
#include <iostream>

//constructor
Maximal::Maximal(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun, const std::string &animal, int strength):
    Transformer(name, level, health, speed, battle, gun),
    _animal(animal),
    _strength(strength) {};

//methods
bool Maximal::transformBeast() { return true; }

void Maximal::setAnimal(const std::string &animal) { _animal = animal; }
std::string Maximal::getAnimal() const { return _animal; }

void Maximal::setStrength(int strength) { _strength = strength; }
int Maximal::getStrength() { return _strength; }
