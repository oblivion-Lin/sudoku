#include "generate.h"
#include <iostream>

void GenerateFinal::Initialize()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			shudu[i][j] = j + 1;
}

void GenerateFinal::Print()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			std::cout << shudu[i][j]<<" ";
		std::cout << std::endl;
	}	
	std::cout << std::endl;
}

int GenerateFinal::Generate(int n) {
	for (int i = 0; i < n; i++) {
		Initialize();
		Print();
	}
	return 0;

}
