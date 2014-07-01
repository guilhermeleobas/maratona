/*
Problema - Fatorial 2
http://br.spoj.com/problems/FATORIA2/
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

	int i;
	int fat;
	int aux;

	fat = 1;
	aux = 0;

	cin >> i;

	for (int cont=1; cont<=i; cont++){
		fat *= cont;
	}

	cout << fat << endl;

	return 0;
}