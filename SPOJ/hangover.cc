/*
Problema - Hangover
http://www.spoj.com/problems/HANGOVER/
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

using namespace std;

#define PI acos(-1)
#define cnt PI/180
typedef vector<vector<pair<int, int> > > graph;

int main (){
	
	vector<pair<float, int> > v;
	float num;
	vector<pair<float, int> >::iterator it;

	v.push_back (make_pair (0.50, 1));

	for (int i=3; i<300; i++){
		v.push_back (make_pair (v.back().first + (float)1/i, i-1));
	}

	while (true){
		cin >> num;

		if (num == 0) break;

		it = lower_bound (v.begin(), v.end(), make_pair (num, 0));

		cout << it->second << " card(s)\n";

	}

	

	return 0;
}
