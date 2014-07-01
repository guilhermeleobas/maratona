/*
Problema - Arvore Genealogica
http://br.spoj.com/problems/GENEAL/
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

typedef vector<vector<int> > graph;

pair<int, int> bfs (graph &g, int start, int sz){

	queue<int> q;
	int atual, next;
	vector<int> visited;
	pair<int, int> p;

	visited.resize (sz, 0);

	q.push (start);

	visited[start] = 0;

	while (!q.empty()){

		atual = q.front();
		q.pop();

		for (int cont=0; cont<g[atual].size(); cont++){
			next = g[atual][cont];
			if (visited[next] == 0){
				visited[next] = visited[atual] + 1;
				q.push (next);
			}
		}

	}

	visited[start] = 0;

	p.first = 0;
	p.second = visited[p.first];

/*	for (int cont=0; cont<visited.size(); cont++){
		cout << visited[cont] << ' ';
	}
	cout << endl;*/

	for (int cont=1; cont<visited.size(); cont++){
		if (visited[cont] > visited[p.first]){
			p.first = cont;
			p.second = visited[p.first];
		}
	}

	// cout << "P.second: " << p.second << endl;
	
	// cout << p.first << endl;
	// p = bfs (g, p.first, sz);

	return p;
}

int main (){
	
	map<string, int> arvore;
	map<int, string> resp;
	pair<map<string, int>::iterator, bool> ret;
	// int g[1100][1100];
	graph g;
	int pai[1100];
	int cont, start, i, j;
	string father, son;
	pair<int, int> p;

	cont = 0;

	int n;

	cin >> n;

	for (int aux=0; aux<1010; aux++){
		pai[aux] = -1;
	}

	g.resize (1010);

	while (n-- > 0){
		cin >> father >> son;

		// if (!cin) break;

		ret = arvore.insert (make_pair (father, cont));
		if (ret.second == true){
			resp.insert (make_pair (cont, father));
			i = cont;
			cont++;
		}
		else {
			i = ret.first->second;
			// Elemento já está lá;
		}

		ret = arvore.insert (make_pair (son, cont));
		if (ret.second == true){
			resp.insert (make_pair (cont, son));
			j = cont;
			cont++;
		}
		else {
			j = ret.first->second;
		}

		pai[j] = i;
		g[i].push_back (j);
		g[j].push_back (i);

	}

	for (int aux=0; aux<arvore.size(); aux++){
		if (pai[aux] < 0) start = aux;
	}


	p = bfs (g, start, arvore.size());
	start = p.first;
	p = bfs (g, p.first, arvore.size());


	if (resp[start] > resp[p.first]){
		cout << resp[p.first] << ' ' << resp[start] << ' ' << p.second << endl;
	}
	else {
		cout << resp[start] << ' ' << resp[p.first] << ' ' << p.second << endl;
	}

	return 0;
}