/*
Problema - Caminhando entre as pontes
http://br.spoj.com/problems/PONTES09/
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

#define max 11111

typedef pair<int, int> no;
typedef vector<vector<no> > graph;

void dijkstra (graph g, int u, int v){

	priority_queue<int> fila;
	vector<int> visited;
	int element, cost, atual;

	visited.resize (g.size(), max);

	visited[u] = 0;

	fila.push (u);

	while (!fila.empty()){

		atual = fila.top();
		fila.pop();

		for (int i=0; i<g[atual].size(); i++){
			element = g[atual][i].first;
			cost = g[atual][i].second;

			if (visited[element] > visited[atual] + cost){
				visited[element] = visited[atual] + cost;
				fila.push (element);
			}	
		}
	}

	cout << visited[v];
}

int main (){


	int n, m, u, v, cost;
	graph g;

	cin >> n >> m;

	g.resize (n+2);

	for (int i=0; i<m; i++){
		cin >> u >> v >> cost;
		g[u].push_back (make_pair (v, cost));
		g[v].push_back (make_pair (u, cost));
	}

	dijkstra (g, 0, n+1);

	return 0;
}