/*
	Codeforces B. I.O.I Round #221 Div. 2: http://codeforces.com/contest/376/problem/B
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
	
	vector<int> v;
	int n, m;
	int a, b, c;
	int result;

	cin >> n >> m;

	v.resize (n, 0);

	for (int i=0; i<m; i++){
		cin >> a >> b >> c;
		a--;
		b--;
		v[a] -= c;
		v[b] += c;
	}

	for (int i=0; i<v.size(); i++){
		if (v[i] < 0) result += (-1)*v[i];
	}

	cout << result << endl;

	

	return 0;
}
