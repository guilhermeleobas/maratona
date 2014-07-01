/*
Problema - Beverages
http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2001
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
#include <iomanip>

using namespace std;

#define PI acos(-1)
#define cnt PI/180
#define INF 99999999

int grafo[110][110];
int rel[110];
vector<string> remap;

void toposort (int n){

	priority_queue <int, vector<int>, greater<int> > pq;
	int atual, next;

	for (int i=0; i<n; i++){
		if (!rel[i])
			pq.push (i);
	}

	while (!pq.empty()){

		atual = pq.top();
		pq.pop();

		cout << ' ' << remap[atual];

		for (int i=0; i<n; i++){
			if (grafo[atual][i]){
				rel[i]--;
				if (rel[i] == 0){
					pq.push (i);
				}
			}
		}
	}
	cout << ".\n\n";

}


int main (){

	ios::sync_with_stdio(false);
	int n, m, test = 0;
	string bebida, bev_a, bev_b;
	map<string, int> mapa;

	while (true){
		cin >> n;
		if (!cin)
			break;

		remap.clear();
		mapa.clear();

		for (int i=0; i<n; i++){
			cin >> bebida;
			mapa[bebida] = mapa.size()-1; 
			remap.push_back (bebida);
		}

		for (int i=0; i<=n; i++){
			rel[i] = 0;
			for (int j=0; j<=n; j++){
				grafo[i][j] = 0;
			}
		}

		cin >> m;

		for (int i=0; i<m; i++){
			cin >> bev_a >> bev_b;
			if (!grafo[mapa[bev_a]][mapa[bev_b]]){
				grafo[mapa[bev_a]][mapa[bev_b]] = 1;
				rel[mapa[bev_b]]++;
			}
		}

		cout << "Case #" << ++test << ": Dilbert should drink beverages in this order:";
		toposort (n);
	}

	return 0;
}
