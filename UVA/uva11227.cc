/*
Problema - The silver bullet
http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2168
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
typedef pair<double, double> point;

bool compare (point p1, point p2, point p3){
	point a, b;

	a.first = p2.first - p1.first;
	a.second = p2.second - p1.second;

	b.first = p3.first - p1.first;
	b.second = p3.second - p1.second;

	if ( (a.first*b.second - a.second*b.first) == 0)
		return true;

	return false;
}

int main (){

	ios::sync_with_stdio(false);
	
	int T, N, sum, maxm, test = 0;
	double x, y;
	set<pair<double, double> > S;

	cin >> T;

	while (T-- > 0){
		cin >> N;

		sum = 0;
		maxm = 1;

		S.clear();

		for (int i=0; i<N; i++){
			cin >> x >> y;
			S.insert (make_pair (x, y));
		}

		for (set<pair<double, double> >::iterator i = S.begin(); i != S.end(); i++){
			for (set<pair<double, double> >::iterator j = next(i); j != S.end(); j++){
				sum = 2;
				for (set<pair<double, double> >::iterator k = next(j); k != S.end(); k++){

					if (compare (*i, *j, *k))
						sum++;
				}
				maxm = max (maxm, sum);
			}
		}

		if (S.size() == 1)
			cout << "Data set #" << ++test << " contains a single gnu.\n";
		else
			cout << "Data set #" << ++test << " contains " << S.size() << " gnus, out of which a maximum of " << maxm << " are aligned.\n";

	}

	

	return 0;
}
