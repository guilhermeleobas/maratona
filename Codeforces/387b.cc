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
	
	int n, m, num, sum = 0;
	vector<int> ai, bi;

	cin >> n >> m;

	ai.resize (n);
	bi.resize (m);

	for (int i=0; i<n; i++)
		cin >> ai[i];

	for (int i=0; i<m; i++)
		cin >> bi[i];

	n--;
	m--;

	do{
		// cout << ai[n] << ' ' << bi[m] << endl;
		if (ai[n] <= bi[m]){
			n--;
			m--;
		}
		else if (ai[n] > bi[m]){
			// cout << "!match\n";
			n--;
			sum++;
		}
	} while (n >= 0 && m >= 0);

	// cout << n << ' ' << m << endl;
	cout << sum+n+1 << endl;
	

	return 0;
}
