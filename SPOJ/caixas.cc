/*
Problema - Desempilhando caixas
http://br.spoj.com/problems/CAIXAS/
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
#include <fstream>
#include <functional>

using namespace std;

#define PI acos(-1)
#define cnt PI/180
typedef vector<vector<int> > caixas;

int recursao (caixas &pilha, int inc_dec, int start, int size){

	if (start < 0 || start >= pilha.size()) return 0;

	if (pilha[start].size() == 0) return 0;

	if (pilha[start].size() <= size) return 0;

	// cout << inc_dec << ' ' << start+inc_dec << endl;

	if (pilha[start].size() > size) return pilha[start].size()-size + recursao (pilha, inc_dec, start+inc_dec, size);
	
}

int main (){
	
	ios::sync_with_stdio (false);

	caixas pilha;
	int n, p, num_caixas, id;
	pair<int, int> par;

	int test = 0;

	while (true){
		cin >> n >> p;

		if (n == 0 && p == 0) break;

		// cout << "aaa\n";
		// cout << "test: " << ++test << ' ' << n << ' ' << p << endl;

		pilha.clear();
		pilha.resize (p);

		for (int i=0; i<p; i++){
			cin >> num_caixas;
			for (int j=0; j<num_caixas; j++){
				cin >> id;
				pilha[i].push_back (id);

				if (id == 1){
					par.first = i;
					par.second = pilha[i].size()-1;
				}
			}
		}

		int size = pilha[par.first].size()-par.second-1;

		// cout << "size: " << par.second << endl;

		cout << size+min(recursao (pilha, 1, par.first+1, par.second), recursao (pilha, -1, par.first-1, par.second)) << endl;

		// cout << pilha[par.first].size()-par.second-1 << endl;
		// cout << recursao (pilha, 1, par.first+1, par.second) << endl;
		// cout << recursao (pilha, -1, par.first-1, par.second) << endl;






	}
	

	

	return 0;
}