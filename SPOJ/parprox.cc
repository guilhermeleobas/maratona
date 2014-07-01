/*
Problema - Pontos
http://br.spoj.com/problems/PARPROX/
Guilherme Leobas
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

#define inf 29999999

int main (){

	vector<pair<int, int> > v;
	pair<int, int> p;
	int n;
	int x, y;
	float dist, aux;

	cin >> n;


	for (int cont = 0; cont<n; cont++){
		cin >> x >> y;
		v.push_back (make_pair (x, y));
	}

	dist = inf;

	for (int i=0; i<v.size(); i++){
		for (int j=i+1; j<v.size(); j++){
			if (i != j){
				aux = sqrt (pow((v[i].first - v[j].first), 2) + pow ( (v[i].second - v[j].second), 2));
				if (dist > aux) dist = aux;
			}
		}
	}

	printf ("%.3f\n", dist);

	return 0;
}
