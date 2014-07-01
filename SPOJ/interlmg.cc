/*
Problema - Interligando a Sildavia
http://br.spoj.com/problems/INTERLMG/
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
typedef pair<double, double> point;
typedef pair<int, int> node;

point pontos[1010];
set<pair<double, node> > graph;
int parent[1010];

double dist (point a, point b){
	return sqrt ( (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second) );
}

void imprime (){
	for (set<pair<double, node> >::iterator it = graph.begin(); it != graph.end(); it++){
		cout << it->first << ' ' << it->second.first << ' ' << it->second.second << endl;
	}
}

int find (int a){
	return a == parent[a] ? a : find (parent[a]);
}

void Union (int a, int b){
	parent[find(a)] = find(b);
}

void kruskal (){

	node v;
	double result = 0;

	for (set<pair<double, node> >::iterator it = graph.begin(); it != graph.end(); it++){
		v = it->second;

		if (find (v.first) != find (v.second)){
			result = max (result, it->first);
			Union (v.first, v.second);
		}
	}

	cout << fixed << setprecision (4) << result << endl;
}


int main (){

	ios::sync_with_stdio(false);
	
	int n;
	double x, y, d;

	while (true){
		cin >> n;

		if (n == 0)
			break;

		for (int i=0; i<=n; i++)
			parent[i] = i;

		graph.clear();

		for (int i=0; i<n; i++){
			cin >> x >> y;
			pontos[i] = make_pair (x, y);
		}

		for (int i=0; i<n; i++){
			for (int j=i+1; j<n; j++){
				d = dist (pontos[i], pontos[j]);
				graph.insert (make_pair (d, make_pair (i, j)));
			}
		}

		if (n > 1)
			kruskal ();
		else
			cout << "0.0000\n";

	}
	

	return 0;
}
