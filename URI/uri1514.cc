/*
Problema - Competição
http://www.urionlinejudge.com.br/judge/pt/problems/view/1514
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

int n, m;

bool one (vector<vector<int> > &v){
	int r = 0;

	for (int i=0; i<n; i++){
		r = 0;
		for (int j=0; j<m; j++){
			r += v[i][j];
		}
		if (r == m)
			return false;
	}

	return true;
}

bool two (vector<vector<int> > &v){
	int r = 0;

	for (int j=0; j<m; j++){
		r = 0;
		for (int i=0; i<n; i++){
			r += v[i][j];
		}

		if (r == 0)
			return false;
	}

	return true;
}

bool three (vector<vector<int> > &v){
	int r = 0;
	
	for (int j=0; j<m; j++){
		r = 0;
		for (int i=0; i<n; i++){
			r += v[i][j];
		}
		if (r == n)
			return false;
	}

	return true;
}

bool four (vector<vector<int> > &v){
	int r = 0;

	for (int i=0; i<n; i++){
		r = 0;
		for (int j=0; j<m; j++){
			r += v[i][j];
		}

		if (r == 0)
			return false;
	}

	return true;
}

int main (){

	ios::sync_with_stdio(false);
	
	int num, resp = 0;
	vector<vector<int> > v;
	
	while (true){
		cin >> n >> m;

		if (!n && !m)
			break;

		v.clear();
		v.resize (n, vector<int> (m, 0));
		resp = 0;

		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				cin >> v[i][j];
			}
		}

		if (one (v))
			resp++;
		if (two(v))
			resp++;
		if (three(v))
			resp++;
		if (four(v))
			resp++;

		cout << resp << endl;		
	}



	return 0;
}
