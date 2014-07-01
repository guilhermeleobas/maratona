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

using namespace std;

#define PI acos(-1)
#define cnt PI/180
typedef vector<vector<pair<int, int> > > graph;

int main (){

	ios::sync_with_stdio(false);
	
	long long num;
	int t;
	int test = 0;

	vector<long long> v;

	for (int i=0; i<57; i++){
		v.push_back (pow (2, i+1)-1);
	}

	cin >> t;

	while (t-- > 0){
		cin >> num;

		cout << "Case " << ++test << ": " << v[num] << endl;
	}
	

	return 0;
}