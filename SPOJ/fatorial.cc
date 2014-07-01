/*
Problema - Fatorial
http://br.spoj.com/problems/FATORIAL/
Guilherme Leobas
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

void imprime (vector<long long int> v){
	for (int i=0; i<v.size(); i++){
		cout << v[i] << endl;
	}
}

void mapeia (vector<long long int> &v){

	v.push_back (1);

	long long int aux;

	for (int i=1; i<1000005; i++){

		aux = v[i-1]*i;

		while (aux%10 == 0){
			aux = aux/10;
		}

		v.push_back(aux%1000000);

	}
}

int main(){

	int num, test;
	vector<long long int> v;

	test = 0;

	mapeia (v);

	while (true){
		cin >> num;

		if (!cin) break;

		cout << "Instancia " << ++test << endl << v[num]%10 << endl << endl;

	}	

	return 0;
}
