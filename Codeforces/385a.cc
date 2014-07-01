/*
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
	int n, c, maximo = 0;

	cin >> n >> c;

	v.resize (n);

	for (int i=0; i<n; i++)
		cin >> v[i];

	for (int i=0; i<n-1; i++)
		maximo = max (maximo, v[i]-v[i+1]);

	cout << maximo-c << endl;

	

	return 0;
}