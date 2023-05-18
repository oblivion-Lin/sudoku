#pragma once

class GenerateFinal {
private:
	int sudoku[9][9];

public:
	void Initialize();
	int Generate(int n);
	void Print();
	void SwapRow(int r1,int r2);
	void SwapColumn(int c1, int c2);
	void SwapNum(int num1, int num2);
	int GetRandomNum(int min, int max);
};