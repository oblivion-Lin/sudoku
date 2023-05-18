#pragma once

class Solver {
private:
	int sudoku[9][9];
public:
	bool GetNumInFile(char* path);
	void Print();
	bool SolveSudoku();
};