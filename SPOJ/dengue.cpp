/*
Problema - Dengue
http://br.spoj.com/problems/DENGUE/
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

#define max 100

typedef vector<vector<int> > graph;

void imprime (graph g){

	for (int i=0; i<g.size(); i++){
		for (int j=0; j<g[i].size(); j++){
			cout << g[i][j]+1 << ' ';
		}
		cout << endl;
	}
}

int bfs (graph g, int start){

	queue<int> fila;
	int height;
	int node, element;
	vector<int> visited;

	visited.resize (g.size(), 0);


	fila.push (start);

	while (!fila.empty()){
		node = fila.front();
		fila.pop();

		for (int cont=0; cont<g[node].size(); cont++){
			element = g[node][cont];
			//Não visitado;
			if (visited[element] == 0){ 
				visited[element] = visited[node]+1;
				fila.push (element);
			}
		}
	}

	height = 0;
	visited[start] = -1;
	
	for (int cont=0; cont<visited.size(); cont++){
		if (height < visited[cont]){
			height = visited[cont];
		}
	}
	
	return height;
}

int main (){

	int n, a, b, height, test;
	vector<int> custo;
	graph g;

	test = 0;

	while (true){
		cin >> n;
		if (n == 0) break;

		g.clear();
		g.resize (n);
		custo.clear();
		custo.resize (n, 0);
		height = 0;

		for (int i=0; i<n-1; i++){
			cin >> a >> b;
			g[a-1].push_back (b-1);
			g[b-1].push_back (a-1);
		}
		// bfs (g, 6);
		// imprime (g);


		for (int cont=0; cont<n; cont++){
			custo[cont] = bfs (g, cont);
		}

		for (int cont=1; cont<n; cont++){
			if (custo[height] > custo[cont]){
				height = cont;
			}	
		}

		cout << "Teste " << ++test << endl;
		cout << height+1 << endl;
		cout << endl;
	}



	return 0;
}