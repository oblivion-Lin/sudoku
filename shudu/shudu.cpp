#include<iostream>
#include <stdlib.h>
#include<fstream>
#include "generate.h"
#include "solve.h"
using namespace std;

int main(int argc, char** argv) {
	//cout << argc << endl;
	//cout << argv << endl;

	int n = 0;	//Êý¶ÀÖÕÅÌÊýÁ¿


	for (int i = 1; i < argc; i+=2) {
		if (!strcmp(argv[i], "-c")) {
			n = atoi(argv[i+1]);
			GenerateFinal gen;
			gen.Generate(n);
		}
		else if (!strcmp(argv[i], "-s")) {
			Solver solver;
			solver.GetNumInFile(argv[i+1]);
			if (!solver.IsValid()) {
				cout << "IsValid" << endl;
				return 0;
			}
			else {
				cout << "Valid" << endl;
			}
			solver.Print();
			solver.SetAnswer();
			solver.SolveSudoku(0,0);
			if (!solver.IsValid()) {
				cout << "IsValid" << endl;
			}
			else {
				cout << "Valid" << endl;
			}
			solver.Print();
		}
		else if (!strcmp(argv[i], "-t")) {		//test
			
			
		}
		else {
			cout<<"undefined" << endl;
		}
	}



	

	//system("pause");
}