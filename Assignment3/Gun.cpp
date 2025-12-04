/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment3
*/

#include "Gun.h"
#include <iostream>

//constructor
Gun::Gun(const std::string &model, int damage):
    _model(model),
    _damage(damage) {};

void Gun::setModel(const std::string &model) { _model = model; }
std::string Gun::getModel() const { return _model; }

void Gun::setDamage(int damage) { _damage = damage; }
int Gun::getDamage() { return _damage; }
