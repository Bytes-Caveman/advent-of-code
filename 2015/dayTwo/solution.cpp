#include <iostream>
#include <string>
#include <fstream>
#include "./calculate.hpp"

std::ifstream input("./input.txt");

int main()
{
	core prog;
	std::string line;
	int total = 0;
	int len = 0;
	
	while (std::getline(input, line)) {
		int value = prog.area(line);
		int ribbon = prog.ribbon(line);
		total = total + value;
		len = len + ribbon;
		
		std::cout << "Area: " << total << "ft\tRibbon: " << len << "\n";
	}
	
	std::cout << "\n\n\nTOTAL WRAPPING PAPER: " << total << "\n\n\n" <<
	"TOTAL RIBBON: " << len;
	return 0;
}
