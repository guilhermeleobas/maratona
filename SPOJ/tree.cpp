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

// typedef pair<int, int> no;
typedef vector<vector<int> > graph;

void imprime (graph g){

	for (int i=0; i<g.size(); i++){
		for (int cnt=0; cnt < g[i].size(); cnt++){
			cout << i+1 << ' ' << g[i][cnt]+1 << endl;
		}
	}

}

int bfs (graph g, int start){

	queue<int> fila;
	vector<int> visited;
	int atual;

	visited.resize (g.size(), 0);

	fila.push (start);

	while (!fila.empty()){
		atual = fila.front();
		fila.pop();

		if (visited[atual] == 1){
			return 0;
		}
		else visited[atual]++;

		for (int i=0; i<g[atual].size(); i++){
			fila.push (g[atual][i]);
		}
	}

	for (int cont=0; cont<visited.size(); cont++){
		if (visited[cont] == 0) return 0;
	}

}

int main (){

	graph g;
	int u, v, n, m;
	// pair<int, int> edge1, edge2;

	cin >> n >> m;

	g.resize (n);

	for (int i=0; i<m; i++){
		cin >> u >> v;
		g[u-1].push_back (v-1);
		// g[v-1].push_back (u-1);
	}

	// imprime (g);
	if (bfs (g, 0) && m == n-1){
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}