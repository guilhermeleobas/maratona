/*
Problema - Mesa da Sra Montagny!
http://br.spoj.com/problems/MESA/
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
	int atual, next, color;

	visited.resize (g.size(), 0);

	color = 1;

	q.push (start);

	visited[start] = color;

	while (!q.empty()){


		atual = q.front();
		q.pop();

		color = visited[atual];

		if (color == 1){
			color = 2;
		}
		else {
			color = 1;
		}

		for (int i=0; i<g[atual].size(); i++){

			next = g[atual][i];

			if (visited[next] == visited[atual]){
				return false;
			}
			else if (visited[next] == 0){
				visited[next] = color;
				q.push (next);
			}
		}

	}

	for (int i=0; i<g.size(); i++){
		color = visited[i];
		for (int j=0; j<g[i].size(); j++){
			if (color == visited[g[i][j]] && visited[g[i][j]] != 0){
				return false;
			}
		}
	}

	return true;
}

int main (){

	ios::sync_with_stdio(false);
	
	int n, m, u, v, test;

	graph g;

	test = 0;
	
	while (true){

		cin >> n >> m;
		if (!cin) break;
		// cin >> m;

		g.clear();
		g.resize (n);

		for (int i=0; i<m; i++){
			cin >> u >> v;

			u--; v--;

			g[u].push_back (v);
			g[v].push_back (u);
		}

		/*for (int i=0; i<g.size(); i++){
			cout << i+1 << ": ";
			for (int j=0; j<g[i].size(); j++){
				cout << g[i][j]+1 << ' ';
			}
			cout << endl;
		}*/

		cout << "Instancia " << ++test << endl;
		if (bfs(g, u)){
			cout << "sim\n\n";
		}
		else {
			cout << "nao\n\n";
		}

	}

	

	return 0;
}