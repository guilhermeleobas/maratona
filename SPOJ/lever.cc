/*
	Codeforces problem A - Div 2 - #221 = http://codeforces.com/contest/376/problem/A
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
	int d, k;
	long long result = 0;

	cin >> s;

	for (int i=0; i<s.size(); i++){
		if (s[i] == '^'){
			k = i;
			break;
		}
	}

	for (int i=0; i<s.size(); i++){
		if (i == k) continue;

		if (s[i] == '=') continue;

		// cout << result << endl;

		if (i < k){
			d = k-i;
			// cout << "dist_a: " << d << endl;
			result -= ((int)s[i]-'0')*d;
		}
		else {
			d = i-k;
			// cout << "dist_b: " << d << endl;
			result += ((int)s[i]-'0')*d;
		}
	}

	if (result == 0){
		cout << "balance\n";
	}
	else if (result < 0){
		cout << "left\n";
	}
	else cout << "right\n";

	

	return 0;
}
