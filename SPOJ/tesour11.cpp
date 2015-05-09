/*
Problema - Tesouro
http://br.spoj.com/problems/TESOUR11/
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

using namespace std;

typedef vector<vector<int> > vetor;

void calc_dist (int x, int y, int d, int &max, vetor &v){
	
	int dist;

	for (int i=0; i<v.size(); i++){
		for (int j=0; j<v.size(); j++){
			dist = abs(x-i) + abs(y-j);
			if (dist == d){
				v[i][j] += 1;
				if (max < v[i][j]){
					max = v[i][j];
				}
			}
		}
	}
}

int main (){

	int n, k, x, y, d, max, res;
	
	cin >> n >> k;

	vector<vector<int> > v(n, vector<int>(n, 0));


	// cout << v.size() << endl;
	// cout << v[1].size() << endl;

	max = 0;
	res = 0;

	for (int cont=0; cont<k; cont++){
		cin >> x >> y >> d;
		calc_dist (x, y, d, max, v);
	}

	for (int i=0; i<v.size(); i++){
		for (int j=0; j<v.size(); j++){
			if (v[i][j] == max){
				res++;
				x = i;
				y = j;
			}
		}
	}

	if (res == 1){
		cout << x << ' ' << y << endl;
	}
	else {
		cout << "-1 -1\n";
	}

	// imprime (v);



	return 0;
}