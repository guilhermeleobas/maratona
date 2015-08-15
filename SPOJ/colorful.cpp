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

typedef struct {
	int color;
	vector<int> node;
	// int cardinality;
} no;

// typedef vector<int> node;
typedef vector<no> graph;

void imprime (graph g){

	for (int i=0; i<g.size(); i++){
		cout << "node: " << i+1 << " color: " << g[i].color << endl;
		for (int j=0; j<g[i].node.size(); j++){
			cout << i+1 << ' ' << g[i].node[j]+1 << endl;
		}
		cout << endl;
	}
}

void bfs (graph &g, map<int, set<int> > &cor, int start){

	int element;

	for (int cont=0; cont<g[start].node.size(); cont++){
		element = g[start].node[cont];
		if (g[element].color != g[start].color){
			cor[g[start].color].insert (g[element].color);
		}
	}

}

int main (){

	int n, m, color, u, v, c;
	graph g;
	map<int, set<int> > cor;
	set<int> Q;

	cin >> n >> m;

	g.resize (n);
	Q.clear();

	for (int cont=0; cont<n; cont++){
		cin >> color;
		g[cont].color = color;
		cor.insert (make_pair <int, set<int> > (color, Q));
	}

	for (int cont=0; cont<m; cont++){
		cin >> u >> v;
		g[u-1].node.push_back (v-1);
		g[v-1].node.push_back (u-1);
	}

	c = 0;

	for (int cont=0; cont<n; cont++){
		bfs (g, cor, cont);
	}

	map<int, set<int> >::iterator it;


	/*
	while (it->second.size() == 0){
		it++;
	}
*/

	it = cor.begin();
	c = it->first;
	// c = 0;


	for (it = cor.begin(); it!= cor.end(); it++){
		// cout << it->first << ' ' << it->second.size() << endl;
		if (it->second.size() > cor[c].size()){
			c = it->first;
		}
		else if (it->second.size() == cor[c].size()){
			if (it->first < c && it->first != 0){
				c = it->first;
			}
		}
	}

	cout << c << endl;

	return 0;
}