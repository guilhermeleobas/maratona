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

int mxm (int n, int d){
	if (n-d*(n/d) < 0)
		return n;
	else
		return (n-d*(n/d));
}

int main (){

	ios::sync_with_stdio(false);
	
	int seg;

	cin >> seg;

	cout << seg/3600 << ':';
	seg = mxm (seg, 3600);
	cout << seg/60 << ':';
	seg = mxm (seg, 60);
	cout << seg << '\n';

	

	return 0;
}
