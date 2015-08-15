/*
Problema - Natureza
http://br.spoj.com/problems/NATUREZA/
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

typedef vector<vector<int> > graph;

void imprime (graph g){

	for (int i=0; i<g.size(); i++){
		cout << i << ": ";
		for (int j=0; j<g[i].size(); j++){
			cout << g[i][j] << ' ';
		}
		cout << endl;
	}
}


int bfs (graph &g, int start){

	int next;
	vector<int> visited;
	stack<int> s;
	int atual;
	int cnt;

	cnt = 0;

	visited.resize (g.size(), 0);

	s.push (start);

	visited[start] = 1;

	cnt = 1;

	while (!s.empty()){


		atual = s.top();
		s.pop();

		for (int i=0; i<g[atual].size(); i++){
			next = g[atual][i];

			if (visited[next] == 0){
				visited[next] = visited[atual]+1;
				s.push (next);

				cnt++;
			}
		}

	}

	return cnt;
	// return big;

}

int main (){

	graph g;
	map<string, int> m;
	map<string, int>::iterator it;
	int cnt, aux, n, c;
	int x, y;
	string a, b;

	while (true){
		cin >> c >> n;

		if (c == 0 && n == 0) break;

		m.clear();
		g.clear();

		g.resize (c);

		for (int cont=0; cont<c; cont++){
			cin >> a;
			m.insert (make_pair (a, cont));
		}

		/*for (it = m.begin(); it != m.end(); it++){
			cout << it->first << ' ' << it->second << endl;
		}*/

		for (int cont=0; cont<n; cont++){
			cin >> a >> b;
			x = m[a];
			y = m[b];

			g[y].push_back (x);
			g[x].push_back (y);
		}

		// imprime (g);

		cnt = 1;

		for (int cont=0; cont<c; cont++){
			aux = bfs (g, cont);
			if (aux > cnt) cnt = aux;
		}

		cout << cnt << endl;
	}
	
	

	

	return 0;
}