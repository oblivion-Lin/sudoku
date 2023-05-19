#include "generate.h"
#include "common.h"
#include <iostream>
#include <random>
#include "solve.h"
using namespace std;


static int seeds[5][9][9] = {
   {{ 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 
	{ 4, 5, 6, 7, 8, 9, 1, 2, 3 },
	{ 7, 8, 9, 1, 2, 3, 4, 5, 6 },
	{ 2, 1, 4, 3, 6, 5, 8, 9, 7 },
	{ 3, 6, 5, 8, 9, 7, 2, 1, 4 },
	{ 8, 9, 7, 2, 1, 4, 3, 6, 5 },
	{ 5, 3, 1, 6, 4, 2, 9, 7, 8 },
	{ 6, 4, 2, 9, 7, 8, 5, 3, 1 },
	{ 9, 7, 8, 5, 3, 1, 6, 4, 2 }},
	{},{},{},{}
};

//合法的交换操作一共九种
static int SwapWay[9][2] = { {0,1},{1,2},{0,2},{3,4},{4,5},{3,5} ,{6,7},{7,8},{6,8} };

void Generator::Initialize()
{
	int index = 0;	//种子编号

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			sudoku[i][j] = seeds[index][i][j];

	for (int i = 0; i < 5; i++) {
		int swapnum = GetRandomNum(0, 8);
		SwapRow(SwapWay[swapnum][0], SwapWay[swapnum][1]);
	}
	
	for (int i = 0; i < 5; i++) {
		int swapnum = GetRandomNum(0, 8);
		SwapColumn(SwapWay[swapnum][0], SwapWay[swapnum][1]);
	}

	for (int i = 0; i < 3; i++) {
		int swapnum1 = GetRandomNum(1, 9);
		int swapnum2 = GetRandomNum(1, 9);
		SwapNum(swapnum1, swapnum2);
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			answer[i][j] = sudoku[i][j];
		}
	}

}

void Generator::Print()
{	
	cout << " -----------------------------------" << endl;
	for (int i = 0; i < 9; i++) {
		cout << "|";
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] != 0)
				cout << " " << sudoku[i][j] << " |";
			else
				cout << "   |";
		}
			
		cout << endl << " -----------------------------------" << endl;
	}	
	cout << endl;
}

void Generator::SwapRow(int r1, int r2)
{
	for (int i = 0; i < 9; i++) {
		int temp = sudoku[r1][i];
		sudoku[r1][i] = sudoku[r2][i];
		sudoku[r2][i] = temp;
	}
}

void Generator::SwapColumn(int c1, int c2)
{
	for (int i = 0; i < 9; i++) {
		int temp = sudoku[i][c1];
		sudoku[i][c1] = sudoku[i][c2];
		sudoku[i][c2] = temp;
	}
}

void Generator::SwapNum(int num1, int num2)
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] == num1) {
				sudoku[i][j] = num2;
			}
			else if (sudoku[i][j] == num2) {
				sudoku[i][j] = num1;
			}
		}
	}
}

void Generator::GenPuzzle(int n,int level,bool flag){
	for (int i = 0; i < n; i++) {
		Initialize();
		//根据难度等级进行挖洞
		if (!flag) {
			switch (level) {
			case 1:
				DigHole(30);
				break;
			case 2:
				DigHole(40);
				break;
			case 3:
				DigHole(60);
				break;
			default:
				break;
			}
		}
		else {
			DigHole(level);
		}
		Print();
	}
	return;
}

void Generator::DigHole(int n){
	for (int i = 0; i < n; i++) {
		int row = GetRandomNum(0,8);
		int column = GetRandomNum(0, 8);
		if (sudoku[row][column] != 0)
			sudoku[row][column] = 0;
		else {
			i--;
		}
	}
	return;
}

void Generator::GenUniPuzzle(int n){
	Solver solver;
	for (int i = 0; i < n; i++) {
		Initialize();
		DigHole(40);
		//Print();
		while (true) {
			solver.SetSudoku(sudoku);
			solver.SetAnswer();
			solver.SolveSudoku(0, 0);
			Pos res = GetDiffPos(solver);
			//cout << res.x<<"  " << res.y << endl;
			if (res.x == -1) {
				break;
			}
			else {
				sudoku[res.x][res.y] = answer[res.x][res.y];
			}
		}
		cout << "index: " << i << endl;
		Print();
	}
	return;
}

Pos Generator::GetDiffPos(Solver solver){
	Pos res;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (answer[i][j] != solver.GetSudoku(i,j)) {
				res.x = i;
				res.y = j;
				return res;
			}
		}
	}

	return res;
}




void Generator::GenerateFinal(int n) {
	for (int i = 0; i < n; i++) {
		Initialize();
		Print();
	}
	return;
}
