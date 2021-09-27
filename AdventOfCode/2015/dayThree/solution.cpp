#include <iostream>
#include <fstream>
#include <Windows.h>

std::ifstream inputFile("input.txt");

struct cords {
    int x;
    int y;
};

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::string input ;
    std::getline(inputFile, input); //spent 2 minutes trying to use '=' on this xD
    cords houseList[input.length() + 1];


    cords startPos ;
    startPos.x = 0;
    startPos.y = 0;
    int visited = 0;
    int total = 0;

    houseList[0] = startPos; //starting position

    cords lastPos;
    lastPos = startPos;
    for (int i = 1; i < input.length() + 1; i++) { //starts at 1st index as 0th is a defined above.
            cords currentPos;
            switch (input[i]) {
                case '^':
                    currentPos.x = lastPos.x;
                    currentPos.y = lastPos.y + 1;
                    lastPos = currentPos;

                case '>':
                    currentPos.x = lastPos.x + 1;
                    currentPos.y = lastPos.y;
                    lastPos = currentPos;

                case 'v':
                    currentPos.x  = lastPos.x;
                    currentPos.y = lastPos.y - 1;
                    lastPos = currentPos;

                    std::cout << "\n" << currentPos.x << ", " << currentPos.y;

                case '<':
                        currentPos.x = lastPos.x - 1;
                        currentPos.y = lastPos.y;
                        lastPos = currentPos;


            }

            for (int i = 0; i < input.length()+1; i++) {
                if (currentPos.x  != houseList[i].x && currentPos.y != houseList[i].y) {
                    visited ++;
                    break;
                }
            }
            total ++;
            std::cout << "\nCURRENT: " << currentPos.x << ", " << currentPos.y << "\t VISITED: " << visited << "\tTOTAL: " << total;


    }
}
