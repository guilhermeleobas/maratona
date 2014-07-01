/*
Problema - Soma
http://br.spoj.com/problems/SOMA/
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
	int soma;
	int aux;

	cin >> i;

	soma = 0;
	aux = 0;

	for (int cont=0; cont<i; cont++){
		cin >> aux;
		soma += aux;
	}

	cout << soma << endl;
	
	return 0;
}