#pragma once

class Solver {
private:
	int sudoku[9][9];
	bool Candiate[9][9][9];

public:
	Solver();
	bool ReadInFile(char* path);
	void Print();
	bool SolveSudoku(int i, int j);
	int CheckRow(int r1,int num);
	int CheckColumn(int c1, int num);
	int CheckSquare(int r,int c,int num);
	void FindRes(int r1,int c1);
	bool IsValid();
	void SetAnswer();
	bool CheckAll(int r1,int c1,int num);
	void WriteInFile();
};