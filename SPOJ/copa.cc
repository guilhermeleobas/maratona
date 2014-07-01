/*
Problema - Copa do Mundo.
http://br.spoj.com/problems/COPA/
Guilherme Leobas
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
	int n, t, soma, part, pts;
	string pais;

	while (true){
		cin >> t >> n;
		if (n == 0 && t == 0) break;
		
		soma = 0;

		for (int cont=0; cont<t; cont++){
			cin >> pais;
			cin >> pts;
			soma += pts;
		}
		cout << 3*n-soma << endl;
	}

	return 0;
}

