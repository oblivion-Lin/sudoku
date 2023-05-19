#pragma once

class Generator {
private:
	int sudoku[9][9];		//������Ŀ
	int answer[9][9];		//������
public:
	void Initialize();		//��ʼ��һ������������
	void GenerateFinal(int n);			//����n����������	
	void Print();					
	void SwapRow(int r1,int r2);		//�н���
	void SwapColumn(int c1, int c2);		//�н���
	void SwapNum(int num1, int num2);		//���ֽ���
	void GenPuzzle(int n,int level,bool flag = false);			//����n���Ѷ�Ϊlevel������
	void DigHole(int n);			//����������n����

};