/*
Codeforces New Year round;
Problem B - New Year present;
http://codeforces.com/contest/379/problem/B
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

void solve (vector<int> &v, int total){

	string s;
	int i = 0;
	bool inverte = false;

	s.clear();

	while (total){
		if (v[i]){
			s += 'P';
			total--;
			v[i]--;
		}

		if (i == 0 || i == v.size()-1)
			inverte = !inverte;

		if (inverte) i++;
		else i--;

		if (!inverte) s += 'L';
		else s += 'R';

	}

	cout << s << endl;
}

int main (){

	ios::sync_with_stdio(false);
	
	int a, total;
	vector<int> v;

	cin >> a;

	v.resize (a, 0);

	total = 0;

	for (int i=0; i<a; i++){
		cin >> v[i];
		total += v[i];
	}

	solve (v, total);
	

	return 0;
}
