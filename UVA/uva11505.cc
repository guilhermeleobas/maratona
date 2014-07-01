/*
Problema - Uva 11505 - Logo
http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2500
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
	
	double x, y;
	string coord;
	int angle, t, quant, dist, theta;

	cin >> t;

	while (t-- > 0){
		cin >> quant;

		x = 0;
		y = 0;
		angle = 0;
		theta = 0;

		for (int i=0; i<quant; i++){
			cin >> coord;

			if (coord == "fd"){
				// Forward;
				cin >> dist;
				x += dist * cos (theta*cnt);
				y += dist * sin (theta*cnt);
			}
			else if (coord == "bk"){
				// Back;
				cin >> dist;
				x -= dist * cos (theta*cnt);
				y -= dist * sin (theta*cnt);
			}
			else if (coord == "lt"){
				// Left;
				cin >> angle;
				theta = (theta + angle)%360;
			}
			else {
				// Right;
				cin >> angle;
				theta = (theta - angle + 360)%360;
			}
		}

		cout << (int) (sqrt(x*x + y*y) + 0.5) << endl;
	}

	

	return 0;
}
