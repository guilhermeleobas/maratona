/*
Problema - Ir e vir.
http://br.spoj.com/problems/IREVIR/
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

typedef vector<int> vetor;
typedef vector<vetor> graph;

bool bfs (graph g, int start){

	int atual, next;
	queue<int> q;
	vector<int> visited;

	visited.resize (g.size(), 0);

	q.push (start);

	while (!q.empty()){

		atual = q.front();
		q.pop();

		for (int cont=0; cont<g[atual].size(); cont++){
			next = g[atual][cont];

			if (visited[next] == 0){
				visited[next] = 1;
				q.push (next);
			}
		}
	}

	for (int cont=0; cont<visited.size(); cont++){
		if (visited[cont] == 0){
			return false;
		}
	}

	return true;
}

int main (){

	graph g;
	int m, n, v, w, p, start;

	while (true){
		scanf ("%d%d", &n, &m);
		if (n == 0 && m == 0) break;

		g.clear();
		g.resize (n);

		for (int i=0; i<m; i++){
			scanf ("%d%d%d", &v, &w, &p);
			
			v--; w--;

			g[v].push_back (w);

			if (p == 2){
				g[w].push_back (v);
			}
		}

		start = v;

		bool flag;

		flag = true;

		for (int i=0; i<n; i++){
			flag = bfs (g, i);
			if (!flag){
				cout << "0\n";
				break;
			}
		}

		if (flag){
			cout << "1\n";
		}

	}



	
	

	

	return 0;
}