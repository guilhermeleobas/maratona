/*
Problema - Elementar meu caro Watson
http://br.spoj.com/problems/WCW/
Guilherme Leobas
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

#define max 100000000

long long int soma = 0;

void imprime (vector<int> &v){
	for (int i=0; i<v.size(); i++){
		cout << v[i] << ' ';
	}
	cout << endl;
}


int main(){

	ios::sync_with_stdio(false);

	vector<int> v;

	// ints;
	int t, n, aux;

	cin >> t;

	while (t-- > 0){
		cin >> n;

		soma = 0;
		v.clear();

		v.push_back (0);

		for (int cont=0; cont<n; cont++){
			cin >> aux;
			v.push_back (aux);
		}

		for (int i=1; i<=v.size()-1; i++){
			// imprime (v);

			// cout << i << endl;

			if (v[i] != i){
				// cout << "v[i]: " << v[i] << ' ' << i << endl;
					// cout << "v.size(): " << v.size() << endl;
				swap (v[i], v[v[i]]);
				i = i-1;
				soma++;
			}

			// cout << i << endl;
		}


		cout << soma << endl;
	}


	return 0;
}

