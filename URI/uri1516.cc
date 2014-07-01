/*
Problema - Imagem
http://www.urionlinejudge.com.br/judge/pt/problems/view/1516
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

int main (){

	ios::sync_with_stdio(false);
	
	char v[55][55], c;

	int n, m, a, b;

	while (true){
		cin >> n >> m;

		if (!n && !m)
			break;

		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				cin >> c;
				v[i][j] = c;
			}
		}

		cin >> a >> b;

		for (int i=0; i<n; i++){
			for (int x=0; x<a/n; x++){
				for (int j=0; j<m; j++){
					for (int y=0; y<b/m; y++){
						cout << v[i][j];
					}
				}
				cout << endl;
			}
		}

		cout << endl;
	}

	

	return 0;
}
