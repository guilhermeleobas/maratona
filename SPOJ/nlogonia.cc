/*
Problema - Divisão da Nlogônia
http://br.spoj.com/problems/NLOGONIA/
Guilherme Leobas
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;


int main (){

	int k, x, y;
	int i, j;

	while (true){
		cin >> k;

		if (k == 0) break;

		cin >> x >> y;

		for (int cont=0; cont<k; cont++){
			cin >> i >> j;

			if (i == x || j == y){
				cout << "divisa\n";
			}
			else if (i > x && j> y){
				cout << "NE\n";
			}
			else if (i <x && j > y){
				cout << "NO\n";
			}
			else if (i <x && j < y){
				cout << "SO\n";
			}
			else cout << "SE\n";
		}
	}

	return 0;
}
