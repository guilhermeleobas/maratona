/*
Problema - PosLivre
http://br.spoj.com/problems/POSLIVRE/
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

int min (int a, int b){
	if (a > b) return b;
	else return a;
}

int max (int a, int b){
	if (a > b) return a;
	else return b;
}

int main (){

	vector<vector<int> > v;

	int w, h, n, sum;
	int x1, y1, x2, y2;

	while (true){
		cin >> w >> h >> n;
		if (w == 0 && h == 0 && n == 0) break;
		v.clear();

		v.resize (w);
		
		for (int cont=0; cont<v.size(); cont++){
			v[cont].resize (h, 0);
		}

		for (int cont=0; cont<n; cont++){
			cin >> x1 >> y1;
			cin >> x2 >> y2;

			x1--; y1--;
			x2--; y2--;

			for (int i=min(x1, x2); i<=max(x1, x2); i++){
				for (int j=min(y1, y2); j<=max(y1, y2); j++){
					v[i][j] = 1;
				}
			}
		}

		sum = 0;

		for (int i=0; i<v.size(); i++){
			for (int j=0; j<v[i].size(); j++){
				if (v[i][j] == 0){
					sum++;
				}
			}
		}

		if (sum == 0){
			cout << "There is no empty spots.\n";
		}
		else if (sum == 1){
			cout << "There is one empty spot.\n";
		}
		else {
			cout << "There are " << sum << " empty spots.\n";
		}

	}


	return 0;
}