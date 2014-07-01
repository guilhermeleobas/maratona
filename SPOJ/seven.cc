/*
	Codeforces Div. 2 - Problem C - Round #221: http://codeforces.com/contest/376/problem/C
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
	
	string s;
	vector<int> v (15, 0);
	int mod[7] = {1869, 6198, 1896, 1689, 1986, 1968, 1698};
	int resto = 0;

	cin >> s;

	for (int i=0; i<s.size(); i++){
		v[(int)s[i]-'0']++;
	}

	v[1]--;
	v[6]--;
	v[8]--;
	v[9]--;

	for (int i=1; i<10; i++){
		while (v[i] > 0){
			cout << i;
			resto = resto*10+i;
			resto = resto%7;
			v[i]--;
		}
	}

	cout << mod[resto];

	for (int i=0; i<v[0]; i++){
		cout << '0';
	}
	cout << endl;

	

	return 0;
}
