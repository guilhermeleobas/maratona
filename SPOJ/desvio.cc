/*
Problema - Desvio de rota
http://br.spoj.com/problems/DESVIO/
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

typedef vector<vector<pair<int, int> > > graph;

void imprime (graph &g){
	for (int i=0; i<g.size(); i++){
		cout << i << ": ";
		for (int j=0; j<g[i].size(); j++){
			cout << g[i][j].second << "\\" << g[i][j].first << ' ';
		}
		cout << endl;
	}
}

void dijkstra (graph &g, int start, int destino){

	priority_queue<pair<int, int>, vector<pair<int, int> >, std::greater<pair<int, int> > > pq;
	vector<int> visited, custo;
	pair<int, int> atual, next;

	visited.resize (g.size(), 0);
	custo.resize (g.size(), 999999);

	atual.first = 0;
	atual.second = start;

	visited[atual.second] = 1;

	pq.push (atual);

	while (!pq.empty()){

		atual = pq.top();
		pq.pop();

		visited[atual.second] = 1;

		// cout << "Atual: " << atual.first << ' ' << atual.second << endl;

		if (atual.second == destino) break;

		for (int cont=0; cont<g[atual.second].size(); cont++){

			next = g[atual.second][cont];

			if (visited[next.second] == 0){
				if (custo[next.second] > (atual.first + next.first)){
					// cout << "Push com: " << custo[next.second] << endl;
					custo[next.second] = atual.first + next.first;
					pq.push (make_pair(custo[next.second], next.second));
				}
			}
		}
	}

/*	for (int cont=0; cont<custo.size(); cont++){
		cout << custo[cont] << ' ';
	}
	cout << endl;*/

	cout << custo[destino] << endl;
}

int main (){
	
	graph g;
	int n, m, c, k, u, v, p;

	while (true){
		cin >> n >> m >> c >> k;

		if (n == 0 && m == 0 && c == 0 && k == 0) break;

		g.clear();
		g.resize (n);

		for (int cont=0; cont<m; cont++){
			cin >> u >> v >> p;

			if (u < c && v < c){
				if (u == v-1 || v == u-1){
					// g[u].push_back (make_pair (p, v));
					// g[v].push_back (make_pair (p, u));

					if (u == v-1){
						g[u].push_back (make_pair(p, v));
					}

					if (v == u-1){
						g[v].push_back (make_pair (p, u));
					}
				}
			}
			else {
				if (u < c && v >= c){
					g[v].push_back (make_pair(p, u));
				}
				else if (v < c && u >= c){
					g[u].push_back (make_pair (p, v));
				}
				else if (u >= c && v >= c){
					g[u].push_back(make_pair (p, v));
					g[v].push_back (make_pair (p, u));
				}
			}
		}

		// imprime (g);
		dijkstra (g, k, c-1);
	}	

	

	return 0;
}