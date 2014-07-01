/*
Problema - Cubra os furos
http://br.spoj.com/problems/FUROS/
Guilherme Leobas
*/

#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <cmath>

using namespace std;

#define PI acos(-1)
#define inf 2147000000

int main (){

	int x, y;
	vector<pair<int, int> > v;
	vector<double> dist;
	double n;
	double maior;
	double aux;
	int test=0;

	while (true){
		cin >> n;
		if (n == 0) break;

		v.clear();
		dist.clear();

		dist.resize (n, 0);

		for (int i=0; i<n; i++){
			cin >> x >> y;
			v.push_back (make_pair(x, y));
		}

		maior = -1;

		for (int i=0; i<v.size(); i++){
			for (int j=0; j<v.size(); j++){
				if (i != j){
					aux = (v[i].first - v[j].first)*(v[i].first - v[j].first) + (v[i].second - v[j].second)*(v[i].second - v[j].second);
					if (aux > dist[i]){
						dist[i] = aux;
					}
				}
			}
		}

		maior = inf;

		for (int i=0; i < dist.size(); i++){
			if (dist[i] < maior && dist[i] != inf){
				maior = dist[i];
			}
		}
		
		maior = sqrt(maior)*2 +5;

		printf ("Teste %d\n", ++test);
		printf ("%.0lf\n\n", maior);



	}

	return 0;
}
