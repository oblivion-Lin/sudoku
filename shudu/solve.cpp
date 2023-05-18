#include "solve.h"
#include<fstream>
#include<iostream>
using namespace std;


bool Solver::GetNumInFile(char* path){
	ifstream fin;
	fin.open(path, ios::in);
	if (!fin.is_open()) {
		cout << "无法找到这个文件！" << endl;
		return false;
	}

	char buff = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			buff = fin.get();
			if (buff == EOF) {
				return false;
			}
			else if (buff != 10 && buff != ' ') {
				if (buff == '$') {
					sudoku[i][j] = 0;
				}
				else{
					sudoku[i][j] = buff - '0';
				}
			}
			else {
				j--;
			}
		}
	}
	fin.close();
	return true;
}

void Solver::Print(){
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool Solver::SolveSudoku(){
	


	return false;
}
