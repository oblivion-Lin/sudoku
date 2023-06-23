#pragma once
#include "generate.h"

class Solver {
private:
	int sudoku[9][9];		//��������
	bool Candiate[9][9][9];			//��ѡԪ��

public:
	Solver();
	bool ReadInFile();		//���ļ��ж�����
	void Print();			//��ӡ���
	bool SolveSudoku(int i, int j);		//������
	int CheckRow(int r1,int num);		//Ѱ��r1����num�ĸ���
	int CheckColumn(int c1, int num);		//Ѱ��c1����num�ĸ���
	int CheckSquare(int r,int c,int num);	//Ѱ��r1��c1���ڷ�����num�ĸ���
	void FindRes(int r1,int c1);	//Ѱ��r1��c1����λ�õĿ��н�
	bool IsValid();			//�ж������Ƿ�Ϸ�
	void SetCandiate();			//Ѱ����������ȫ��λ�õĿ��н�
	bool CheckAll(int r1,int c1,int num);		//���r1��c1����λ���Ƿ������дnum
	void WriteInFile();			//������д���ļ���
	void SetSudoku(int arr[9][9]);		//������ʼ��	
	int GetSudoku(int i ,int j) { return sudoku[i][j]; };		//����������ĳһԪ��	
	
};