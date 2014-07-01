/*
Problema - Mice and Maze - v² log v
http://www.spoj.com/problems/MICEMAZE/
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
typedef pair<int, int> node;

int dijkstra (graph &g, int e, int t){

	priority_queue <node, vector<node>, greater<node> > pq;
	node atual, next;
	vector<int> visited (g.size(), INF);

	atual.first = 0;
	atual.second = e;
	pq.push (atual);

	visited[atual.second] = 0;

	while (!pq.empty()){

		atual = pq.top();
		pq.pop();

		for (int i=0; i<g[atual.second].size(); i++){
			next = g[atual.second][i];

			if (visited[next.second] > visited[atual.second] + next.first){
				visited[next.second] = visited[atual.second] + next.first;
				pq.push (next);
			}
		}
	}

	int sum = 0;

	visited[e] = INF;

	for (int i=0; i<visited.size(); i++){
		if (visited[i] <= t || i == e)
			sum++;
	}

	return sum;
}

int main (){

	ios::sync_with_stdio(false);
	
	graph g;
	int n, m, t, e, u, v, w;

	cin >> n >> e >> t >> m;

	g.resize (n);

	for (int i=0; i<m; i++){
		cin >> u >> v >> w;
		g[v-1].push_back (make_pair (w, u-1));
	}

	cout << dijkstra (g, e-1, t) << endl;



	return 0;
}
