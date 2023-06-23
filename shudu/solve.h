#pragma once
#include "generate.h"

class Solver {
private:
	int sudoku[9][9];		//数独棋盘
	bool Candiate[9][9][9];			//候选元素

public:
	Solver();
	bool ReadInFile();		//从文件中读数据
	void Print();			//打印结果
	bool SolveSudoku(int i, int j);		//解数独
	int CheckRow(int r1,int num);		//寻找r1行中num的个数
	int CheckColumn(int c1, int num);		//寻找c1列中num的个数
	int CheckSquare(int r,int c,int num);	//寻找r1，c1所在方框中num的个数
	void FindRes(int r1,int c1);	//寻找r1，c1所在位置的可行解
	bool IsValid();			//判断数独是否合法
	void SetCandiate();			//寻找整个数独全部位置的可行解
	bool CheckAll(int r1,int c1,int num);		//检查r1，c1所在位置是否可以填写num
	void WriteInFile();			//将数据写入文件中
	void SetSudoku(int arr[9][9]);		//数独初始化	
	int GetSudoku(int i ,int j) { return sudoku[i][j]; };		//返回数独中某一元素	
	
};