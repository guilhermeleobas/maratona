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

int m[2010][2010];
int w[2010];
int v[2010];

int main (){

	ios::sync_with_stdio(false);
	
	int s, n;
	int value, peso;

	cin >> s >> n;

	for (int i=1; i<=n; i++){
		cin >> peso >> value;
		w[i] = peso;
		v[i] = value;
	}

	for (int i=1; i<=n; i++){
		for (int j=1; j<=s; j++){
			if (w[i] > j)
				m[i][j] = m[i-1][j];
			else
				m[i][j] = max (m[i-1][j], m[i-1][j-w[i]] + v[i]);
		}
	}

	cout << m[n][s] << endl;

	return 0;
}
