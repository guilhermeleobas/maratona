/*
Problema - Mice and Maze - v³ log v
http://www.spoj.com/problems/MICEMAZE/
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

#define max 999999

typedef vector<vector<pair<int, int> > > graph;
typedef pair<int, int> P;

bool dijkstra (graph &g, int start, int destino, int t){

	priority_queue <P, vector<P>, greater<P> > pq;
	vector<int> visited, custo;
	P atual, next;

	visited.resize (g.size(), 0);
	custo.resize (g.size(), max);

	atual.first = 0;
	atual.second = start;

	pq.push (atual);

	while (!pq.empty()){

		atual = pq.top();
		pq.pop();

		visited[atual.second] = 1;

		if (atual.second == destino) break;

		for (int cont=0; cont<g[atual.second].size(); cont++){
			next = g[atual.second][cont];

			if (visited[next.second] == 0){

				if (custo[next.second] > (atual.first + next.first)){
					custo[next.second] = atual.first + next.first;
					pq.push (make_pair (custo[next.second], next.second));
				}

			}
		}

	}

	if (custo[destino] > t) return false;

	return true;

}

void imprime (graph g){
	for (int i=0; i<g.size(); i++){
		cout << i+1 << ": ";
		for (int j=0; j<g[i].size(); j++){
			cout << g[i][j].second+1 << ' ';
		}
		cout << endl;
	}
}

int main (){
	
	graph g;
	int n, e, t, m, u, v, w;
	bool flag;
	int sum = 0;

	cin >> n >> e >> t >> m;

	e--;

	g.clear();
	g.resize (n);

	for (int cont=0; cont<m; cont++){
		cin >> u >> v >> w;

		u--;
		v--;

		g[u].push_back (make_pair(w, v));
	}

	// imprime (g);

	for (int cont=0; cont<n; cont++){
		if (dijkstra (g, cont, e, t) || cont == e){
			// cout << "chegou com: " << cont+1 << endl;
			sum++;
		}
	}

	// cout << e+1 << endl;

	cout << sum << endl;
	

	return 0;
}