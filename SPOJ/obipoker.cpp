/*
Problema - Mini-Poker
http://br.spoj.com/problems/OBIPOKER/
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

void imprime (vector<int> v){

	for (int cont=1; cont<v.size(); cont++){
		cout << v[cont] << ' ';
	}

	cout << endl;
}

int if5 (vector<int> v){

	int cont = 0;

	while (v[cont] == 0) cont++;

	for (int i=cont; i<cont+4; i++){
		if (v[i] != v[i+1]){
			return 0;
		}
	}

	return cont+200;
}

int if4 (vector<int> v){

	int cont=1; 

	while (v[cont] != 2){
		cont++;
	}

	return cont;
}

int if3 (vector<int> v){

	int x, y;

	for (int cont=1; cont<=13; cont++){
		if (v[cont] == 3){
			return cont+140;
		}
	}

	y = 1;

	while (v[y] != 2){
		y++;
	}

	x = y+1;

	while (v[x] != 2){
		x++;
	}

	return ((3*x)+(2*y)+20);

}

int if2 (vector<int> v){

	for (int cont=1; cont<=13; cont++){
		if (v[cont] == 4){
			return cont+180;
		}
		else if (v[cont] == 3){
			return cont+160;
		}
	}
}

int main (){

	vector<int> v;

	int n;
	int aux;
	int c;
	int test = 0;

	cin >> n;

	while (n-- > 0){

		v.clear();
		v.resize (14, 0);
		c = 0;

		for (int cont=0; cont<5; cont++){
			cin >> aux;
			v[aux] += 1;
		}

		// imprime (v);

		for (int cont=1; cont<=13; cont++){
			if (v[cont] != 0) c++;
		}

		// cout << c << endl;

		cout << "Teste " << ++test << endl;

		if (c == 5){
			cout << if5(v) << endl;
		}
		else if (c == 4){
			cout << if4(v) << endl;
		}
		else if (c == 3){
			cout << if3(v) << endl;
		}
		else {
			cout << if2(v) << endl;
		}

		cout << endl;

	}


	return 0;
}