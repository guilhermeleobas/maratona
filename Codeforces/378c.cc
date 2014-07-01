/*
	http://codeforces.com/contest/378/problem/C
	Codeforces Div 2. Round #222;
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

int v[510][510];
int n, m, k;

void imprime (){
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (v[i][j] < 0) cout << '#';
			else if (v[i][j] == 0) cout << 'X';
			else cout << '.';
		}
		cout << endl;
	}
}

void dfs (pair<int, int> start, int empty){

	stack<pair<int, int> > s;
	pair<int, int> atual;
	int maximo = empty - k;

	if (!empty) maximo = INF;

	s.push (start);

	v[start.first][start.second] = 1;
	maximo--;

	while (!s.empty() && maximo){

		atual = s.top();
		s.pop();

		if (v[atual.first][atual.second] < 0) continue;

		if (maximo <= 0) break;

		if (atual.first-1 >= 0 && v[atual.first-1][atual.second] == 0) {
			s.push (make_pair (atual.first-1, atual.second));
			v[atual.first-1][atual.second] = 1;
			maximo--;
		}

		if (maximo <= 0) break;

		if (atual.second-1 >= 0 && v[atual.first][atual.second-1] == 0){
			s.push (make_pair (atual.first, atual.second-1));
			v[atual.first][atual.second-1] = 1;
			maximo--;
		}

		if (maximo <= 0) break;

		if (atual.second+1 < m && v[atual.first][atual.second+1] == 0){
			s.push (make_pair (atual.first, atual.second+1));
			v[atual.first][atual.second+1] = 1;
			maximo--;
		}

		if (maximo <= 0) break;

		if (atual.first+1 < n && v[atual.first+1][atual.second] == 0){
			s.push (make_pair (atual.first+1, atual.second));
			v[atual.first+1][atual.second] = 1;
			maximo--;
		}
	}

}

void dfs2 (){
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (v[i][j] == 0) v[i][j] = 1;
		}
	}
}


int main (){

	ios::sync_with_stdio(false);
	
	cin >> n >> m >> k;
	char c;
	pair<int, int> start;
	int empty = 0;

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> c;
			if (c == '.') v[i][j] = 0;
			else v[i][j] = -1;

			if (c == '.'){
				empty++;
				start.first = i;
				start.second = j;
			}
		}
	}
	
	if (k) dfs (start, empty);
	else dfs2();

	imprime ();

	return 0;
}
