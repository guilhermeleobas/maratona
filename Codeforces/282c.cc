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

int solver (vector<pair<int, int> > &v){

	bool valid = true;
	int sum = 0;
	int resp = 0;

	while (valid){
		valid = false;
		sum = 0;

		for (int i=0; i<v.size(); i++){
			if (sum == 0){
				if (v[i].second == 0){
					sum += 1;
					v[i].second = 1;
				}
			}
			else {
				if (v[i].first >= sum && v[i].second == 0){
					v[i].second = 1;
					sum++;
				}
			}
		}

		// cout << sum << endl;
		// for (int i=0; i<v.size(); i++)
			// cout << v[i].first << ' ' << v[i].second << endl;
		// cout << endl;

		if (sum != 0){
			valid = true;
			resp++;
		}
	}

	return resp;
}

int main (){

	ios::sync_with_stdio(false);
	
	vector<pair<int, int> > v;
	int n, num;

	cin >> n;

	for (int i=0; i<n; i++){
		cin >> num;
		v.push_back (make_pair (num, 0));
	}

	sort (v.begin(), v.end());

	cout << solver (v) << endl;

	

	return 0;
}
