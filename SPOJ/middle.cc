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
	
	int n;
	cin >> n;

	vector<int> v (n, 0);


	for (int i=0; i<n; i++){
		cin >> v[i];
	}

	sort (v.begin(), v.end());

	if (n % 2 != 0)
		cout << v[n/2] << endl;
	else
		cout << (v[n/2] + v[(n+1)/2])/2 << endl;

	

	return 0;
}
