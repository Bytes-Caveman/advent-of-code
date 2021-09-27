#include <iostream>
#include <fstream>

//X is 0th row, and Y is 1st row - makes sense? didn't think so.
#define X 0 
#define Y 1

std::ifstream inputFile("./input.txt");
std::string input;

int main()
{
	std::getline(inputFile, input);
	inputFile.close();
	
	int cordinates[2] [input.length() + 2]; //+2 for start pos
	cordinates[0][0] = 0;
	cordinates[1][0] = 0;
	int visited = 1;
	int total = 0;
	int currentX = 0;
	int currentY = 0;
	
	std::cout << input.length();
	
	for (unsigned int i = 0; i < input.length(); i++) { 
		switch(input[i]) {
			case '^':
			cordinates[X][i + 1] = cordinates[X][i];
			cordinates[Y][i + 1] = cordinates[Y][i] += 1;
			currentY ++;
			
			case '>':
			cordinates[X][i + 1] = cordinates[X][i] += 1;
			cordinates[Y][i + 1] = cordinates[Y][i];
			currentX ++;
			
			case 'v':
			cordinates[X][i + 1] = cordinates[X][i];
			cordinates[Y][i + 1] = cordinates[Y][i] -= 1;
			currentY --;
			
			case '<':
			cordinates[X][i + 1] = cordinates[X][i] -= 1;
			cordinates[Y][i + 1] = cordinates[Y][i];
			currentX --;
		}
		
		if (input[i] != '^' && input[i] != '>' && input[i] != 'v' && input[i] != '<') { 
			std::cout << "\n\n\n\nBAD BAD BAD BAD BAD BAD!" << i;
			break; // yes, good. stops bad characters.
		}
		

		for (unsigned int iterations = 0; iterations < i; iterations ++) {
			if (cordinates[X][iterations] == currentX && cordinates[Y][iterations] == currentY) {
				visited += 1;
				break;
			} else {
				continue;
			}
		}
		total += 1;
		std::cout << "CURRENT: " << cordinates[0][i] << ", " <<
			cordinates[1][i] << "\tVISITED: " << visited << "\tTOTAL: " << total << '\n' ;
	}
	
	
	std::cout << "\n\n\nFINISHING CORDS: " << currentX << ", " << currentY ;
	
	return 0;
}
