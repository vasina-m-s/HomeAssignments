/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment4
*/

#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "Transformer.h"

class Decepticon: public Transformer {
    public:
        //constructor
        Decepticon(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun, int evil, int mind);
        Decepticon(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun, int evil);
        Decepticon(const std::string &name, int level, int health, int speed, Battle battle, Gun* gun);
        Decepticon(const std::string &name, int level, int health, int speed, Battle battle);
        Decepticon(const std::string &name, int level, int health, int speed);
        Decepticon(const std::string &name, int level, int health);
        Decepticon(const std::string &name, int level);
        Decepticon(const std::string &name);

        //methods
        virtual bool doEvilPlan();
	virtual bool evilLaugh();
	void transform() override;

        //getters
        int getEvil();
        int getMind();

        //setters
        void setEvil(int evil);
        void setMind(int mind);

	friend std::ostream& operator<<(std::ostream &os, Decepticon &d);

    private:
        int _evil;
        int _mind;
};

#endif