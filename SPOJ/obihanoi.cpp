/*
Problema - OBIHanoi
Link: http://br.spoj.com/problems/OBIHANOI/
Guilherme Leobas
*/

#include <iostream>
#include <cmath>

using namespace std;

int main (){

	int num;
	int cont=1;

	while (true){
		cin >> num;
		if (num == 0) break;

		cout << "Teste " << cont++<< endl;
		cout << (int)((pow(2, num)) - 1) << endl;

		cout << endl;
	}


	return 0;
}