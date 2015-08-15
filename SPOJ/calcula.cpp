/*
Problema - CALCULA
http://br.spoj.com/problems/CALCULA/
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

using namespace std;

#define num(conta) (int)conta-'0';

int main (){

	int sum, aux, cnt, i, op, x, test;
	string conta;

	sum = 0;
	aux = 0;
	test = 0;

	while (true){
		cin >> i;
		if (i == 0) break;

		cin >> conta;

		cnt = 0;
		sum = 0;

		while (conta[cnt] != '+' && conta[cnt] != '-'){
			sum = sum*10 + num(conta[cnt++]);
		}

		int cont = cnt;

		while (cont < conta.size()){
			
			if (conta[cont++] == '+') op = 1;
			else op = 0;

			aux = 0;
			
			while (conta[cont] != '+' && conta[cont] != '-' && cont < conta.size()){
				x = num(conta[cont++]);
				
				if (x != 0){
					aux = aux*10 + x;
				}
				else {
					aux = aux*10;
				}
			}
	
			if (op == 1){
				sum += aux;
			}
			else {
				sum -= aux;
			}
		}
		cout << "Teste " << ++test << endl << sum << endl << endl;
	}


	return 0;
}