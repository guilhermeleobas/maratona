/*
Problema - Orkut
http://br.spoj.com/problems/ORKUT/
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

typedef vector<string> connection;

struct orkut {
	int weight;
	string father;
	connection nodes;
};

typedef struct orkut graph;

void imprime (vector<graph> g){

	for (int cont=0; cont<g.size(); cont++){
		for (int i=0; i<g[cont].weight; i++){
			cout << g[cont].nodes[i] <<' ';
		}
		cout << endl;
	}
}

bool sortme (graph a, graph b){
	return a.weight < b.weight;
}

bool check_condition (connection &vanessa, vector<graph> &g, int i){

	int tamanho = g[i].nodes.size();
	bool findme = true;
	int cont = 0;

	for (int cont=0; cont<tamanho; cont++){
		/*if (find(vanessa.begin(), vanessa.end(), g[i].nodes[cont]) != g[i].nodes.end()){
			return false;
		}*/
		findme = false;
		// cont = 0;
		for (int x=0; x<vanessa.size(); x++){
			if (vanessa[x] == g[i].nodes[cont]){
				findme = true;
			}
		}
		if (findme == false){
			return findme;
		}
	}
	return true;
}

void making_friends (connection &vanessa, vector<graph> &g){

	vector<graph>::iterator it;
	int tamanho = g.size();
	bool trocou = true;

	while (trocou){
		trocou = false;
		for (int cont=0; cont<tamanho; cont++){
			if (g[cont].weight != -1 && check_condition (vanessa, g, cont)){
				vanessa.push_back (g[cont].father);
				g[cont].weight = -1;
				trocou = true;
			}
		}
	}
}


int main (){

	int n, quant, teste;

	// Strings;
	string name;

	// graph
	vector<graph> g;

	// Vanessa
	connection vanessa;

	while (true){

		cin >> n;
		if (n == 0) break;

		// friends.clear();
		g.clear();
		g.resize (n);
		vanessa.clear();

		for (int cont=0; cont<n; cont++){
			cin >> name;
			// friends.push_back (name);
		}

		for (int cont=0; cont<n; cont++){
			cin >> g[cont].father >> g[cont].weight;
			for (int i=0; i<g[cont].weight; i++){
				cin >> name;
				g[cont].nodes.push_back (name);
			}
		}

		stable_sort (g.begin(), g.end(), sortme);

		making_friends (vanessa, g);

		cout << "Teste " << ++teste << endl;

		if (vanessa.size() == n){
			for (int cont=0; cont<vanessa.size(); cont++){
				cout << vanessa[cont] << ' ';
			}
		}
		else {
			cout << "impossivel";
		}

		cout << endl << endl;
	}

	return 0;
}