/*
Problema - Final mundial de 2008
http://br.spoj.com/problems/MINIMO/
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
int graph[110][110][110];

void floyd_warshall (int n){
	
	for (int i=1; i<=n; i++){
		for (int j=0; j<n; j++){
			for (int k=0; k<n; k++){
				graph[i][j][k] = min (graph[i-1][j][k], graph[i-1][j][i-1] + graph[i-1][i-1][k]);
			}
		}
	}
}

int main (){

	ios::sync_with_stdio(false);

	int n, m, c, u, v, w, t, test=0;

	while (true){
		cin >> n >> m;
		if (!cin)
			break;

		for (int i=0; i<=n; i++){
			for (int j=0; j<=n; j++){
				for (int k=0; k<=n; k++){
					if (j == k)
						graph[i][j][k] = 0;
					else
						graph[i][j][k] = INF;
				}
			}
		}

		for (int i=0; i<m; i++){
			cin >> u >> v >> w;
			graph[0][u-1][v-1] = min (graph[0][u-1][v-1], w);
		}

		floyd_warshall (n);

		cin >> c;

		cout << "Instancia " << ++test << endl;
		for (int i=0; i<c; i++){
			cin >> u >> v >> t;

			if (graph[t][u-1][v-1] == INF)
				cout << "-1\n";
			else
				cout << graph[t][u-1][v-1] << endl;
		}
		cout << endl;

	}

	return 0;
}
