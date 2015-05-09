/*
Problema - Rede otica
http://br.spoj.com/problems/REDOTICA/
Guilherme Leobas
*/

#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>

using namespace std;

typedef pair<int, int> vertice;
typedef pair<int, vertice> edge;
typedef set<edge> graph;

vector<int> parents;

void imprime (graph &g){

	vertice v;
	int cost;
	graph::iterator it;

	for (it = g.begin(); it != g.end(); it++){
		v = it->second;
		cout << v.first+1 << ' ' << v.second+1 << ' ' << endl;
	}
}

pair<int, int> ordena (int a, int b){
	return a > b ? make_pair(b, a) : make_pair (a, b);
}

int findset (int a){
	while (parents[a] != a){
		a = parents[a];
	}

	return a;
}

void join (int a, int b){
	parents[findset(a)] = findset (b);
}

graph kruskal (graph &rede){

	graph result;
	int max_custo = 0;

	graph::iterator it;
	int no1, no2;
	vertice v;

	for (it = rede.begin(); it != rede.end(); it++){

		v = it->second;
		
		no1 = v.first;
		no2 = v.second;

		if (findset(no1) != findset(no2)){

			v = ordena (v.first, v.second);

			result.insert (make_pair (0, v));
			join (no1, no2);
			max_custo += it->first;
		}
		
		
	}

	cout << max_custo << endl;
	return result;
}

int main (){

	//Lista de adjacencia;
	graph rede;
	graph result;
	vertice v;
	edge e;

	//Ints;
	int n, m, teste;
	int a, b, cost;

	teste = 0;

	while (true){
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		rede.clear();
		parents.clear();

		for (int cont=0; cont<m; cont++){
			cin >> a >> b >> cost;
			v = make_pair (a-1, b-1);
			e = make_pair (cost, v);
			rede.insert (e);
		}

		//Gera o vector de parents;
		parents.resize (n);
		for (int cont=0; cont<parents.size(); cont++){
			parents[cont] = cont;
		}

		result = kruskal (rede);
		cout << "Teste " << ++teste << endl; 
		// imprime (result);
		cout << endl;
	}


	return 0;
}