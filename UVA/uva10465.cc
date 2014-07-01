/*
Problema - Homer Simpson - Uva 10465
http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1406
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

using namespace std;

int main (){
	
	int n, m, t, mx, ny, max;
	vector<int> v;
	vector<int> tempo;

	// cin >> m >> n >> t;

	while (scanf ("%d%d%d", &m, &n, &t) != EOF){

		v.clear();
		v.resize (t+1, 0);
		tempo.clear();
		tempo.resize (t+1, t);

		mx = 0;
		ny = 0;

		if (n < m) swap (n, m);


		for (int cont=m; cont<=t; cont++){
			v[cont] = v[cont-m] + 1;
			tempo[cont] = tempo[cont-m] - m;
		}

		
		for (int cont=n; cont<=t; cont++){
			if (cont%m == 0){
				if (v[cont-n]+1 > v[cont]){
					v[cont] = v[cont-n] + 1;
				}
			}
			else {
				if ( (tempo[cont]) > (tempo[cont-n] - n) ){
					v[cont] = v[cont-n] + 1;
					tempo[cont] = tempo[cont-n] - n;
				}
			}
		}


		/*for (int cont=0; cont<=t; cont++){
			cout << v[cont] << ' ';
		}
		cout << endl;
		for (int cont=0; cont<=t; cont++){
			cout << tempo[cont] << ' ';
		}
		cout << endl;*/

		if (t < m && t < n){
			cout << "0 " << t << endl;
		}
		else {
			if (tempo[t] == 0){
				cout << v[t-tempo[t]] << endl;
			}
			else {
				cout << v[t-tempo[t]] << ' ' << tempo[t] << endl;
			}
		}

	}

	

	return 0;
}