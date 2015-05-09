/*
Problema - Pedagio
http://br.spoj.com/problems/PEDAGIO/
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

#define max 1000

// typedef pair<int, int> par;
typedef vector<int> vetor;
typedef vector<vetor> graph;


void imprime (graph g){

	for (int i=0; i<g.size(); i++){
		cout << i+1 << ": ";
		for (int j=0; j<g[i].size(); j++){
			cout << g[i][j]+1 << ' ';
		}
		cout << endl;
	}

}

void bfs (graph g, int start, int custo){

	set<int> result;
	vector<int> visited;
	queue<int> q;

	int atual, next;

	visited.clear();
	visited.resize (g.size(), 0);

	q.push (start);

	visited[start] = 1;

	while (custo-- > 0 && !q.empty()){

		int sz = q.size();

		for (int u=0; u<sz; u++){

			atual = q.front();
			q.pop();


			for (int cont=0; cont<g[atual].size(); cont++){

				next = g[atual][cont];

				// cout << "Next: " << next+1 << endl;

				result.insert (next+1);

				if (visited[next] == 0){
					visited[next] = 1;
					q.push (next);
				}
			}


		}

	}

	result.erase (start+1);

	set<int>::iterator it;

	for (it=result.begin(); it!=result.end(); it++){
		cout << *it << ' ';
	}

	cout << endl;
	
	

}

int main (){
	
	int c, e, l, p;
	int x, y;
	int test = 0;

	// ios::sync_with_stdio(false);

	graph g;

	while (true){
		// cin >> c >> e >> l >> p;
		scanf ("%d%d%d%d", &c, &e, &l, &p);

		if (c == 0 && e == 0 && l == 0 && p == 0) break;

		g.clear();
		g.resize (c);


		for (int i=0; i<e; i++){
			scanf ("%d %d", &x, &y);
			x--;
			y--;
			g[x].push_back (y);
			g[y].push_back (x);
		}

		// imprime (g);

		// cout << p- << endl;

		cout << "Teste " << ++test << endl;
		bfs (g, l-1, p);
		cout << endl;
	}


	

	return 0;
}