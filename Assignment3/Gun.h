/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment3
*/

#ifndef GUN_H
#define GUN_H

#include <string>

class Gun {
	public: //constructor and destructor
        	Gun(const std::string &model = "Unknow", int damage = 0);
        	~Gun();

        	//Getters
        	std::string getModel() const;
        	int getDamage();

        	//Setters
        	void setModel(const std::string &model);
        	void setDamage(int damage);

	private:
        	std::string _model;
        	int _damage;
};

#endif