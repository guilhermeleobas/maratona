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

bool comp (int a, int b){
	return a>b;
}

int main (){

	ios::sync_with_stdio(false);
	
	vector<int> v;
	int n;
	int s, d;

	cin >> n;

	v.resize (n);

	for (int i=0; i<n; i++)	
		cin >> v[i];

	int l, r;

	l = 0;
	r = v.size()-1;

	bool vez = true;

	s = 0;
	d = 0;

	while (l <= r){
		// cout << l << ' ' << r << endl;
		if (v[l] > v[r]){
			if (vez){
				s += v[l];
			}
			else {
				d += v[l];
			}
			l++;
		}
		else {
			if (vez){
				s += v[r];
			}
			else {
				d += v[r];
			}
			r--;
		}
		vez = !vez;
	}

	cout << s << ' ' << d << endl;


	return 0;
}
