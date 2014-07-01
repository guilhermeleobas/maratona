/*
Problema - Bits trocados
http://br.spoj.com/problems/BIT/
Guilherme Leobas
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <fstream>

using namespace std;

int main (){
	
	int test, v, num;
	int vetor[5];

	test = 0;
	while (true){
		cin >> num;
		if (num == 0) break;


		for (int cont=0; cont<5; cont++){
			vetor[cont] = 0;
		}

		vetor[0] = num/50;
		num = num%50;

		vetor[1] = num/10;
		num = num%10;

		vetor[2]  = num/5;
		vetor[3] = num%5;

		printf ("Teste %d\n", ++test);
		for (int cont=0; cont<4; cont++){
			cout << vetor[cont] << ' ';
		}
		printf ("\n\n");
	}

	

	return 0;
}