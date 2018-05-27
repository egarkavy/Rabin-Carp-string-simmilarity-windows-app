#include "FileReader.h"
#include <iostream>
#include <fstream>
#include <string>

std::string readFile(std::string path)
{

	std::string accomulator = "";
	std::ifstream file(path);
	file >> accomulator;
	//file.open(path, std::ifstream::in);
	
	if (file.is_open()) {
		std::string temp = "";
		while (std::getline(file, temp))
		{
			accomulator += temp;
		}
		file.close();
	}

	return accomulator;

}
