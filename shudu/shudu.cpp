#include<iostream>
#include <stdlib.h>
#include "generate.h"
using namespace std;

int main(int argc, char** argv) {
	cout << argc << endl;
	//cout << argv << endl;

	int n = 0;	//Êý¶ÀÖÕÅÌÊýÁ¿


	for (int i = 1; i < argc; i+=2) {
		//cout << argv[i] << endl;
		if (!strcmp(argv[i], "-c")) {

			n = atoi(argv[i+1]);
			//cout << "n:" << n << endl;
			GenerateFinal gen;
			gen.Generate(n);
		}
		else if (!strcmp(argv[i], "-s")) {
			cout << "path" << endl;
		}
		else {
			cout<<"undefined" << endl;
		}
	}



	

	//system("pause");
}