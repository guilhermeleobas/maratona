/*
Problema - Satellites
http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1162
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
#define raio 6440

typedef vector<vector<pair<int, int> > > graph;

int main (){

	ios::sync_with_stdio(false);
	double s, alfa;
	string type;
	double arc, corda;

	while (true){
		cin >> s >> alfa >> type;

		if (!cin) break;

		if (type == "min") alfa = (double)alfa/60;

		if (alfa > 180){
			alfa = 360-alfa;
		}

		// cout << s << ' ' << alfa << ' ' << type << endl;

		arc = (double)PI*(s+raio)*alfa/180;

		corda = 2*(s+raio)*sin(((double)alfa/2) * PI/180);

		cout << setprecision (6) << fixed << arc << ' ' << corda << endl;
	}	

	

	return 0;
}