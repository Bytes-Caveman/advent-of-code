#include <iostream>
#include <fstream>
#include <string>

std::ifstream input("input.txt");

std::string line;
unsigned int iterations = 0;
int currentFloor = 0;

int main()
{
	//part one
	std::getline(input, line);
	while (iterations < line.length()) {
		if (line[iterations] == '(') {
			currentFloor++;
		} else if (line[iterations] == ')') {
			currentFloor--;
		}
		iterations++;
	}
	std::cout << "part one: " << currentFloor ;
	
	//part two
	int output;
	iterations = 0;
	currentFloor = 0;
	std::getline(input, line);
	while (iterations < line.length()) {
		if (line[iterations] == '(') {
			currentFloor++;
		} else if (line[iterations] == ')') {
			currentFloor--;
		}
		
		if (currentFloor < 0) {
			output = iterations++;
			break; //i spent a while wondering why the floor was way too high, I forgot to break here xD
		}
		iterations++;
	}
	std::cout << "\npart two: " << output ;
	
	return 0;
}
