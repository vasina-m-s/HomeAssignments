/*
* Marina Vasina
* st140082@student.spbu.ru
* Assignment2a
*/

#include <iostream>
#include <fstream>
#include <filesystem>

int main() {
	//read the file
	std::ifstream infile;
 	infile.open("source.pdf",std::ios::binary|std::ios::in);

	//file's size
	size_t sizef = std::filesystem::file_size("source.pdf");
	std::cout << "File's size is " << sizef << std::endl;

	//Allocate space for an array
	char* buffer = new char[sizef];


	// read file
	infile.read(buffer, sizef);


	// reverse file
	for (size_t i = 0; i < sizef / 2; i++) {
		char a = buffer[i];
		buffer[i] = buffer[sizef - i - 1];
		buffer[sizef - i -1] = a;
	}

	// add reversed file to new one
	std::ofstream outfile;
	outfile.open("temppdf.pdf",std::ios::binary|std::ios::out);

	outfile.write(buffer, sizef);

	//close all
	infile.close();
	outfile.close();

	// clear memory
	delete[] buffer;

	return 0;
}