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
#define CNT PI/180
#define INF 99999999
const double EPS = 1e-10;
typedef vector<vector<pair<int, int> > > graph;

int main (){

	ios::sync_with_stdio(false);
	
	int n;

	cin >> n;

	vector<int> v (n);

	for (int i=0; i<n; i++)
		cin >> v[i];
	
	sort (v.begin(), v.end());
	double area = 0.0;
	for (int i=0; i<n; i++){
		if (i%2)
			area += v[i]*v[i];
		else
			area -= v[i]*v[i];
	}

	cout << fixed << setprecision (10) << abs(area)*PI << endl;
	
	

	return 0;
}
