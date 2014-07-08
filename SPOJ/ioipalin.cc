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

int m[2][5001];

void lcs (char c, string &s, int t){
	int k = (t+1)%2;

	// k represent the line above t but in modulo 2;

	for (int j=1; j<=s.size(); j++){
		if (c == s[j-1])
			m[k][j] = m[t][j-1] + 1;		
		else
			m[k][j] = max (m[t][j ], m[k][j-1]);
	}
}

void print (string s){
	int n = s.size();

	for (int i=0; i<2; i++){
		for (int j=0; j<=n; j++){
			cout << m[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main (){

	ios::sync_with_stdio(false);
	
	int n;
	string s;

	cin >> n >> s;
	int t = 0;
	for (int i=s.size()-1; i >= 0; i--){
		lcs (s[i], s, t);
		t = (t+1)%2;
	}

	int ans = max (m[0][n], m[1][n]);

	cout << n - ans << endl;


	

	return 0;
}
