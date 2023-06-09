#include "solve.h"
#include<fstream>
#include<iostream>
using namespace std;
ifstream fin;
ofstream file;

Solver::Solver(){
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				Candiate[i][j][k] = false;
			}
			sudoku[i][j] = 0;
		}
	}
}

bool Solver::ReadInFile(){
	char buff;
	
	//获取数独初始值
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
	return true;
}

//打印结果
void Solver::Print(){
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//解数独
bool Solver::SolveSudoku(int i,int j){
	if (j == 9) {			//如果是最后一列，则直接从下一行开始
		return SolveSudoku(i + 1, 0);
	}
	else if (i == 9) {		//如果是最后一行，则直接结束
		return true;
	}
	else if (sudoku[i][j] != 0) {		//如果不是空格，则填写下一个位置
		return SolveSudoku(i, j + 1);
	}

	for (int k = 0; k < 9;k++) {
		// 如果遇到不合法的数字，就跳过
		if (Candiate[i][j][k]) {		
			if (CheckAll(i, j, k + 1)) {
				sudoku[i][j] = k + 1;
				// 如果找到一个可行解，立即结束
				if (SolveSudoku(i, j + 1)) {
					return true;
				}
				sudoku[i][j] = 0;				//回溯
			}		
		}
	}
	return false;
}

int Solver::CheckRow(int r1, int num){
	int res = 0;
	for (int i = 0; i < 9; i++) {
		if (sudoku[r1][i] == num)
			res++;
	}
	return res;
}

int Solver::CheckColumn(int c1, int num){
	int res = 0;
	for (int i = 0; i < 9; i++) {
		if (sudoku[i][c1] == num)
			res++;
	}
	return res;
}

int Solver::CheckSquare(int r, int c, int num){
	int r_st = r / 3 * 3;
	int c_st = c / 3 * 3;
	//cout<<"r c" << r_st
	int res = 0;
	for (int i = r_st; i < r_st + 3; i++) {
		for (int j = c_st; j < c_st + 3; j++) {
			//cout << sudoku[i][j] << " ";
			if (sudoku[i][j] == num)
				res++;
		}
		//cout << endl;
	}

	return res;
}

void Solver::FindRes(int r1, int c1){
	for (int i = 1; i <= 9; i++) {
		if (!CheckRow(r1, i) && !CheckColumn(c1, i) && !CheckSquare(r1, c1, i)) {
			Candiate[r1][c1][i - 1] = true;
		}
	}
}

bool Solver::IsValid(){
	//检查行与列
	for (int i = 0; i < 9; i++) {
		for (int num = 1; num <= 9; num++) {
			if (CheckRow(i, num)>1 || CheckColumn(i, num)>1) {
				return false;
			}
		}
	}
	//cout<<"row and cloumn check" << endl;
	//检查方格
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int num = 1; num <= 9; num++) {
				if (CheckSquare(i*3,j*3,num)>1) {
					return false;
				}
			}
		}
	}


	return true;;
}

void Solver::SetCandiate(){
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			FindRes(i, j);
		}
	}
}

bool Solver::CheckAll(int r1, int c1, int num){
	int res1 = CheckRow(r1, num);
	int res2 = CheckColumn(c1, num);
	int res3 = CheckSquare(r1, c1, num);
	if (!res1 && !res2 && !res3)
		return true;
	else
		return false;
}

void Solver::WriteInFile() {
	
	if (file.is_open()){
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				file << sudoku[i][j] <<" ";
			}
			file << endl;
		}
		file << endl;

		//file.close();
	}
	else 
		cout << "Unable to write the answer in file";
}

void Solver::SetSudoku(int arr[9][9]){
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			sudoku[i][j] = arr[i][j];
		}
	}
}

