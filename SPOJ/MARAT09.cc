/*
Problema - Maratona
http://br.spoj.com/problems/MARAT09/
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
	
	int n, m, aux;
	vector<int> v;
	int vale = 0;

	cin >> n >> m;

	for (int cont=0; cont<n; cont++){
		cin >> aux;
		v.push_back (aux);
	}

	v.push_back (42195);

	for (int cont=1; cont<v.size(); cont++){
		if ( (v[cont] - v[cont-1]) > m){
			vale = 1;
		}
	}

	// cout << i << endl;

	if (vale == 0){
		cout << "S";
	}
	else  cout << "N";


	

	return 0;
}