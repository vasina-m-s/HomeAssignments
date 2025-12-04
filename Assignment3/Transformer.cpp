/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment3
*/

#include "Transformer.h"
#include <iostream>
#include "Gun.h"
#include "Battle.h"

Transformer::Transformer(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun):
    _name(name), _level(level), _health(health), _speed(speed), _battle(battle), _gun(gun){};

Transformer::~Transformer() {}


bool Transformer::move() { return true; }
bool Transformer::fire() { return true; }
bool Transformer::transform() { return true; }

void Transformer::setName(const std::string &name) { _name = name; }
std::string Transformer::getName() const { return _name; }

void Transformer::setLevel(int level) { _level = level; }
int Transformer::getLevel() { return _level; }

void Transformer::setHealth(int health) { _health = health; }
int Transformer::getHealth() { return _health; }

void Transformer::setSpeed(int speed) { _speed = speed; }
int Transformer::getSpeed() { return _speed; }

void Transformer::setGun(Gun* gun) { _gun = gun; }
Gun* Transformer::getGun() { return _gun; }

Battle Transformer::getBattle() { return _battle; }