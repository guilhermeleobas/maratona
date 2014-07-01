/*
Problema - Meteoro
http://br.spoj.com/problems/METEORO/
Guilherme Leobas
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

#define inf 29999999

int max (int a, int b){
	if (a > b) return a;

	return b;
}

int min (int a, int b){
	if (a < b) return a;

	return b;
}

int main (){

	int x1, x2, y1, y2;
	int i, j;
	int k, soma, test;

	test = 0;

	while (true){
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) break;

		cin >> k;

		soma = 0;

		// cout << x1 << ' ' << x2 << " - " << y1 << ' ' << y2 << endl;

		for (int cont=0; cont<k; cont++){
			cin >> i >> j;

			// cout << i << ' ' << j << endl;

			if (i >= min (x1, x2) && i <= max (x1, x2)){
				if (j >= min (y1, y2) && j <= max (y1, y2)){
					soma++;
				}
			}
		}

		cout << "Teste " << ++test << endl << soma << endl << endl;
	}

	return 0;
}
