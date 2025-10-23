/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment2b
*/

#include <iostream>
#include <sstream>
#include <string>


int main() {
	//creating initial conditions
	std::string s;
	std::getline(std::cin, s);
	std::stringstream stream(s);

	double* stack = new double[100];
	int poin = -1;
    	std::string sym;

    	//algorithm
    	while (stream >> sym)
	{	
		if (std::isdigit(sym[0]) || (sym.size() > 1 && std::isdigit(sym[1])))
		{
			stack[++poin] = std::stod(sym);
		}
		else
		{
			if (poin >= 1)
			{
				double a = stack[poin--];
				double b = stack[poin--];
				double result;

				if (sym == "+")
				{
					result = b + a;
			        } 
				else if (sym == "-")
				{
					result = b - a;
				} 
				else if (sym == "*")
				{
					result = b * a;
				} 
				else if (sym == "/")
				{
					if (a == 0)
					{
						std::cout << "It cannot be divided by 0" << std::endl;
						delete[] stack;
						return 1;
					}
					result = b / a;
				} 
				else
				{
					std::cout << "Unknowen operator" << std::endl;
					delete[] stack;
					return 1;
				}
				stack[++poin] = result;

			}
			else
			{
				std::cout << "The operands are out of range. Check your input" << std::endl;
				delete[] stack;
				return 1;
			}
		}
	}

	if (poin != 0){
		std::cout << "There are too many operands. Check your input" << std::endl;
		delete[] stack;
		return 1;
	}


	std::cout << "Result is " << stack[poin] << std::endl;
	delete[] stack;
	return 0;

}
