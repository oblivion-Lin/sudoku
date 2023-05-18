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
			solver.SolveSudoku();
			solver.Print();
		}
		else {
			cout<<"undefined" << endl;
		}
	}



	

	//system("pause");
}