/*
Problema - 
http://br.spoj.pl/problems/ENERGIA/
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

	queue<int> q;
	vector<int> visited;
	int atual, next;

	visited.resize (g.size(), 0);

	q.push (start);

	visited[start] = 1;

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
		if (visited[cont] == 0) return false;
	}

	return true;

}

int main (){
	
	graph g;
	bool flag = true;
	int e, l, x, y, start, test;

	test = 0;

	while (true){
		scanf ("%d%d", &e, &l);

		if (e == 0 && l == 0) break;

		g.clear();

		g.resize (e);

		for (int cont=0; cont<l; cont++){
			scanf ("%d%d", &x, &y);

			x--; y--;

			g[x].push_back (y);
			g[y].push_back (x);
		}

		start = x;

		flag = bfs (g, start);

		cout << "Teste " << ++test << endl;

		if (flag){
			cout << "normal\n\n";
		}
		else {
			cout << "falha\n\n";
		}
	}
	

	

	return 0;
}