/*
Problema - AssaltoMG
http://br.spoj.com/problems/ASSALTMG/
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

using namespace std;

#define for_i(start, end) for (int i=start; i<end; i++)
#define for_j(start, end) for (int j=start; j<end; j++)

typedef struct {
	int num_chaves;
	unsigned int key;
} diretor;

void imprime (unsigned int x, int d){

	for (int i = d-1; i >= 0; i--){
		cout << ((x >> i) & 1);
	}

	cout << endl;

	// cout <<  __builtin_popcount(x) << endl;

    // std::cout << ((v >> i) & 1);
}

int sortme (pair<int, int> p1, pair<int, int> p2){

	return p1.first < p2.first;
}

int sequestra (int m, int d, vector<diretor> v){

	vector<pair<int, int> > comb;
	int i;
	unsigned int bits;
	unsigned int x;
	unsigned int comp;
	unsigned int aux;
	comb.clear();

	bits = pow (2, d) - 1;
	x = 0;
	aux = 0;

	// imprime (bits, d);

	// x = gera as combinações;
	// comp = percorre e vou dividindo o numero;

	while (x != (bits+1u)){

		comp = x;
		aux = 0;
		i = 0;

		for (int cont=d-1; cont>=0; cont--){
			if ((comp >> cont) & 1){
				aux |= v[cont].key;
			}
		}

		if (__builtin_popcount(aux) >= m){
			comb.push_back (make_pair (__builtin_popcount(aux), __builtin_popcount(x)));
		}

		// imprime (x, d);

		x += 1u;
	}

	i = 0;

	if (comb.empty()){
		return 0;
	}
	else {
		for (int cont=1; cont<comb.size(); cont++){
			if (comb[cont].first < comb[i].first){
				i = cont;
			}
			else if (comb[cont].first == comb[i].first && comb[cont].second < comb[i].second){
				i = cont;
			}
		}

	}

	/*for (int cont=0; cont<comb.size(); cont++){
		cout << comb[cont].first << ' ' << comb[cont].second;
		cout << endl;
	}
	cout << endl;*/


	return comb[i].second;
}

int main (){

	unsigned int x;

	int t, m, d, num, aux;
	vector<diretor> v;

	// x |= (1u << 0);

	// cout << x << endl;

	cin >> t;

	while (t-- > 0){
		cin >> m >> d;

		v.clear();
		v.resize (d);
		x = 0b00000000000000000000000000000000;

		for (int cont=0; cont<d; cont++){

			cin >> num;

			v[cont].num_chaves = num;
			v[cont].key = x;

			// Faz o shift-left (mascara de bits/bitmask) e muda apenas o bit correspondente ao 
			// valor representado por aux para 1;
			for (int i=0; i<num; i++){
				cin >> aux;
				v[cont].key |= (1u << aux-1);	
			}
		}

		num = sequestra (m, d, v);

		if (num == 0 && m != 0){
			cout << "Desastre!\n";
		}
		else {
			cout << num << endl;
		}

	}

	return 0;
}