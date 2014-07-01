/*
Problema - Rota Critica
http://br.spoj.com/problems/ROTA/
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
typedef vector<vector<pair<int, int> > > graph;

map<pair<string, string>, int> write_back;

void print (graph &g){
	for (int i=0; i<g.size(); i++){
		cout << i << ": ";
		for (int j=0; j<g[i].size(); j++){
			cout << g[i][j].first << '/' << g[i][j].second << ' ';
		}
		cout << endl;
	}
}

void pre_bfs (graph &g){
	queue<int> q;
	int atual, next;
	vector<int> visited (g.size(), 0);
	
	q.push (0);

	visited[0] = 1;

	while (!q.empty()){

		atual = q.front();
		q.pop();

		visited[atual] = 1;

		for (int i=0; i<g[atual].size(); i++){
			next = g[atual][i].first;

			if (!visited[next]){
				g[atual][i] = make_pair (next, 1);
				q.push (next);
			}
		}
	}

}

bool bfs (graph &g, int u, int v){
	
	queue<int> q;
	int atual, next;
	vector<int> visited (g.size(), 0);
	
	q.push (0);

	visited[0] = 1;

	while (!q.empty()){

		atual = q.front();
		q.pop();

		// cout << "visitou: " << atual << endl;

		for (int i=0; i<g[atual].size(); i++){
			next = g[atual][i].first;

			if ( !(atual == u && i == v) && !visited[next]){
				// cout << "next: " << next << endl;
				visited[next] = 1;
				q.push (next);
			}
		}
	}

	for (int i=0; i<visited.size(); i++){
		if (!visited[i])
			return false;
	}

	return true;
}

bool compare (pair<string, string> a, pair<string, string> b){
	return write_back[a] < write_back[b];
}


bool solver (graph &g, map<int, string> retorno, map<pair<string, string>, int> &write_back){

	bool cond = false;

	vector<pair<string, string> > escrita;

	for (int i=0; i<g.size(); i++){
		for (int j=0; j<g[i].size(); j++){
			if (g[i][j].second){
				g[i][j].second = 0;
				
				if (!bfs (g, i, j)){
					cond = true;
					escrita.push_back (make_pair(retorno[g[i][j].first], retorno[i]));
					// cout << retorno[g[i][j].first] << ' ' << retorno[i] << endl;
				}

				g[i][j].second = 1;
			}
		}
	}

	if (cond){
		sort (escrita.begin(), escrita.end(), compare);

		for (int i=0; i<escrita.size(); i++){
			cout << escrita[i].first << ' ' << escrita[i].second << endl;
		}
	}


	return cond;
}



int main (){

	ios::sync_with_stdio(false);
	
	map<string, int> mapa;
	map<int, string> retorno;
	int n, m;
	string u, v;
	graph g;


	while (true){
		cin >> n >> m;

		if (!n && !m)
			break;

		mapa.clear();
		retorno.clear();
		write_back.clear();
		g.clear();
		g.resize (n);

		for (int i=0; i<n; i++){
			cin >> u;
			mapa[u] = mapa.size()-1;
			retorno[mapa[u]] = u;
		}

		for (int i=0; i<m; i++){
			cin >> u >> v;
			write_back[make_pair (u, v)] = i;
			g[mapa[v]].push_back (make_pair (mapa[u], 0));
		}

		/*for (map<string, int>::iterator it = mapa.begin(); it != mapa.end(); it++){
			cout << it->first << ' ' << it->second << endl;
		}*/

		pre_bfs (g);
		// print (g);
		if ( !solver (g, retorno, write_back) )
			cout << "Nenhuma\n";
		else 
			cout << endl;
	}

	

	return 0;
}
