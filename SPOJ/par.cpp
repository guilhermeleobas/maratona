/*
Problema - Par
http://br.spoj.com/problems/PAR/
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

int main (){

	int n, x, y, teste;
	string a, b;

	n = 1;
	teste = 0;

	while (n != 0){
		cin >> n;
		if (n == 0) break;

		cin >> a >> b;

		cout << "Teste " << ++teste << endl;

		for (int cont=0; cont<n; cont++){
			cin >> x >> y;
			/*if ((x+y)%2==0){
				cout << a;
			}
			else {
				cout << b;
			}*/

			((x+y)%2 == 0) ? cout << a : cout << b;
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}