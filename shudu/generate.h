#pragma once

struct Pos {
	int x = -1;
	int y = -1;
};
extern class Solver;

class Generator {
private:
	int sudoku[9][9];		//数独题目
	int answer[9][9];		//数独答案
public:
	void Initialize();		//初始化一个完整的数独
	void GenerateFinal(int n);			//生成n个数独终盘	
	void Print();					
	void SwapRow(int r1,int r2);		//行交换
	void SwapColumn(int c1, int c2);		//列交换
	void SwapNum(int num1, int num2);		//数字交换
	void GenPuzzle(int n,int level,bool flag = false);			//生成n个难度为level的数独
	void DigHole(int n);			//在数组上挖n个洞
	void GenUniPuzzle(int n);
	int GetSudoku(int i, int j) { return sudoku[i][j]; };
	Pos GetDiffPos(Solver solver);
};