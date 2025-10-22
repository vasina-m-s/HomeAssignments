/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment1
*/

#include "hello.h"

#include <iostream>

void myproject :: sayHello () {
	std::cout << "Hello, world" << std::endl;
	std::string s;
	while (true){
		std::getline(std::cin, s);
		std::cout << "Hello, " << s << "!" << std::endl;
	}
}
