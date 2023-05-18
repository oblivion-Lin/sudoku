#include "generate.h"
#include <iostream>
#include <random>
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

void GenerateFinal::Initialize()
{
	int index = 0;	//种子编号

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			sudo[i][j] = seeds[index][i][j];

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
}

void GenerateFinal::Print()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << sudo[i][j]<<" ";
		cout << endl;
	}	
	cout << endl;
}

void GenerateFinal::SwapRow(int r1, int r2)
{
	for (int i = 0; i < 9; i++) {
		int temp = sudo[r1][i];
		sudo[r1][i] = sudo[r2][i];
		sudo[r2][i] = temp;
	}
}

void GenerateFinal::SwapColumn(int c1, int c2)
{
	for (int i = 0; i < 9; i++) {
		int temp = sudo[i][c1];
		sudo[i][c1] = sudo[i][c2];
		sudo[i][c2] = temp;
	}
}

void GenerateFinal::SwapNum(int num1, int num2)
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudo[i][j] == num1) {
				sudo[i][j] == num2;
			}
			else if (sudo[i][j] == num2) {
				sudo[i][j] == num1;
			}
		}
	}
}

int GenerateFinal::GetRandomNum(int min,int max)
{
	random_device seed;		//硬件生成随机数种子
	ranlux48 engine(seed());	//利用种子生成随机数引擎
	uniform_int_distribution<> distrib(min, max);	//设置随机数范围，并为均匀分布
	return distrib(engine);
}


int GenerateFinal::Generate(int n) {
	for (int i = 0; i < n; i++) {
		Initialize();
		Print();
	}
	return 0;

}
