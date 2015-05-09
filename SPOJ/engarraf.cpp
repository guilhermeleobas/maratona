/*
Problema - Engarrafamento
http://br.spoj.com/problems/ENGARRAF/
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

#define max 99999

typedef pair<int, int> node;
typedef vector<vector<node> > graph;

void imprime (graph g){

	for (int cont=0; cont<g.size(); cont++){
		for (int i=0; i<g[cont].size(); i++){
			cout << cont+1 << ' ' << g[cont][i].first+1 << ' ' << g[cont][i].second << endl;
		}
	}
}

void dijkstra (graph g, int u, int v){

	// Variaveis;
	vector<int> peso;
	priority_queue<node> fila;
	int atual, elemento, custo;

	peso.resize (g.size(), max);

	peso[u] = 0;

	fila.push (make_pair (0, u));

	
	while (!fila.empty()){

		atual = fila.top().second;
		fila.pop();

		for (int cont=0; cont<g[atual].size(); cont++){
			custo = g[atual][cont].first;
			elemento = g[atual][cont].second;

			if (peso[elemento] > peso[atual] + custo){
				peso[elemento] = peso[atual] + custo;
				fila.push (make_pair (peso[elemento], elemento));
			}
		}
	}

	if (peso[v] == max){
		cout << "-1\n";
	}
	else{
		cout << peso[v] << endl;
	}
}

int main (){

	int n, m;
	int a, b, custo;
	graph g;
	node vertice;
	pair<int, int> no;

	while (true){
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		g.clear();
		g.resize (n);

		for (int cont=0; cont<m; cont++){
			cin >> a >> b >> custo;

			// cout << a << ' ' << b << ' ' << custo << endl;
			// no = make_pair (b-1, custo);
			g[a-1].push_back (make_pair (custo, b-1));
		}
		
		cin >> a >> b;

		dijkstra (g, a-1, b-1);

		// imprime (g);
	}

	return 0;
}




























































/*typedef vector<int>::iterator iT;

#define foreach(it,S)  for(iT it=S.begin();it!=S.end();it++)

void func(){

vector<int> G[N_Vertices];
int W[N_Vertices][N_Vertices];
int D[N_vertices];
bool vis[N_vertices];

vis<-false;
W<-INF;
lê arestas;

//computa rota mínima de s a t
priority_queue<pair<int,int> > Q;
D[s]=0;
Q.push(make_pair<int,int>(0,s));
while(!Q.empty()){
         int u, v;
         u=Q.top().second; Q.pop();
         
         if(vis[u]) continue;
         if(u==t) break;

         vis[u]=true;
         foreach(it,G[u]){
                  v=*it;
                  if(D[v]>D[u]+W[u][v]){
                          D[v]=D[u]+W[u][v];
                          Q.push(make_pair<int,int>(-D[v],v));
                  }
         }  
}

if(D[t]<INF) print D[t];
else print "impossivel";

}*/
