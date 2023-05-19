#include<iostream>
#include <stdlib.h>
#include<fstream>
#include "generate.h"
#include "solve.h"
#include "common.h"
using namespace std;
//六种参数类型
enum { P_c, P_s, P_n, P_n_m, P_n_r, P_n_u };//参数类型

int main(int argc, char** argv) {
	int patype = -1;		//参数类型
	
	int n = 0;	//数独数量
	int m = 0; //辅助参数
	char pathname[20];


	if (!strcmp(argv[1], "-c")) {		//解析命令
		if (argc!=3) {
			cout<<"The number of parameters is incorrect" << endl;
			return 0;
		}	
		n = atoi(argv[2]);
		patype = P_c;
	}
	else if (!strcmp(argv[1], "-s")) {
		if (argc != 3) {
			cout << "The number of parameters is incorrect" << endl;
			return 0;
		}
		memcpy(pathname, argv[2],strlen(argv[2])+1);
		patype = P_s;
	}
	else if (!strcmp(argv[1], "-n")) {	
		if (argc >= 3) {
			n = atoi(argv[2]);
			if (n > 10000 || n < 1) {
				cout << "The value of parameter m is incorrect and should be 1-10000" << endl;
				return 0;
			}
		}
		else {
			cout << "The number of parameters is incorrect" << endl;
			return 0;
		}

		if (argc == 3) {
			patype = P_n;
		}
		else if (argc == 4 && !strcmp(argv[3], "-u")) {		
				patype = P_n_u;
		}
		else if (argc == 5 && !strcmp(argv[3], "-m")) {
			m = atoi(argv[4]);
			if (m > 3 || m < 1) {
				cout << "The value of parameter m is incorrect and should be 1-3" << endl;
				return 0;
			}
			patype = P_n_m;
		}
		else if (argc == 5 && !strcmp(argv[3], "-r")) {
			m = atoi(argv[4]);
			if (m > 55 || m < 20) {
				cout << "The value of parameter r is incorrect and should be 20-55" << endl;
				return 0;
			}
			patype = P_n_r;
		}
		else {
			cout << "undefined command" << endl;
			return 0;
		}
	}
	else if (!strcmp(argv[1], "-t")) {
		n = atoi(argv[2]);
		for(int i = 0;i<n;i++)
			cout<<GetRandomNum(0,9) << endl;
	}
	else {

		cout << "undefined command" << endl;
			return 0;
	}

	
	//选择相应操作
	switch (patype) {
	case P_c: {
		Generator generator;
		generator.GenerateFinal(n);
		break;
	}	
	case P_s: {
		Solver solver;
		solver.ReadInFile(pathname);
		if (!solver.IsValid()) {
			cout << "IsValid" << endl;
			return 0;
		}
		else {
			cout << "Valid" << endl;
		}
		solver.Print();
		solver.SetCandiate();
		solver.SolveSudoku(0, 0);
		if (!solver.IsValid()) {
			cout << "IsValid" << endl;
		}
		else {
			cout << "Valid" << endl;
		}
		solver.Print();
		solver.WriteInFile();
		break; 
	}
	case P_n: {
		Generator generator;
		generator.GenPuzzle(n, 1);
		break;
	}	
	case P_n_m: {
		Generator generator;
		generator.GenPuzzle(n, m);
		break;
	}
	case P_n_r: {
		Generator generator;
		generator.GenPuzzle(n, m,true);
		break;
	}
	case P_n_u:
		Generator generator;
		generator.GenUniPuzzle(n);
		break;
	default:
		cout << "wrong!" << endl;
		break;
	}
	//system("pause");
}