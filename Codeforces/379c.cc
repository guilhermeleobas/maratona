/*
Codeforces Goodbye 2013 challange contest - Problem C;
http://codeforces.com/contest/379/problem/C
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

vector<int> v, index;

bool compare (int a, int b){
	if (v[a] < v[b]) return true;
	else return false;
}

int main (){

	ios::sync_with_stdio(false);
	int n;

	cin >> n;

	v.resize (n, 0);
	index.resize (n, 0);

	for (int i=0; i<n; i++){
		cin >> v[i];
		index[i] = i;
	}

	sort (index.begin(), index.end(), compare);

	int menor = v[index[0]];

	for (int i=1; i<v.size(); i++){
		if (menor >= v[index[i]]){
			v[index[i]] = ++menor;
		}
		else menor = v[index[i]];
	}

	for (int i=0; i<v.size(); i++){
		cout << v[i] << ' ';
	}
	cout << endl;

	return 0;
}
