/*
Problema - Intersection (Lineseg)
http://www.spoj.com/problems/LINESEG/
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
#define INF 9999999
typedef vector<vector<pair<int, int> > > graph;

typedef struct {
	int angular;
	int x1, y1, x2, y2;
} reta;

int delta (int a, int b){
	return abs(b-a);
}

bool point (reta r){
	if (r.x1 == r.x2 && r.y1 == r.y2) return true;

	return false;
}

bool ver_hori (reta r, reta s){

	// cout << r.y1 << ' ' << r.y2 << ' ' << s.y1 << endl;

	if (r.angular == 0 && s.angular == 0 || r.angular == INF && s.angular == INF) return false;
	else if (r.angular == 0 && s.angular == INF) swap (r, s);

	if (r.y1 <= s.y1 && s.y1 <= r.y2){
		if (s.x1 <= r.x1 && r.x1 <= s.x2){
			return true;
		}
	}

	return false;
}

int ver_ver (reta r, reta s){

	if (r.angular == 0 || s.angular == 0) return false;

	if (r.x1 != s.x1 && r.x2 != s.x2) return false;

	if (max (r.y2, s.y2) > r.y2) swap (r, s);

	if (s.y2 == r.y1) return 1; // POINT;
	else if (s.y2 > r.y1 && (point(r) || point(s))) return 1;
	else if (s.y2 > r.y1) return 2; // SEGMENT;
	else if (s.y2 < r.y1) return 0; // NO;

	return false;
}

bool hori_ver (reta r, reta s){

	if (r.angular == 0 && s.angular == 0 || r.angular == INF && s.angular == INF) return false;
	else if (r.angular == INF && s.angular == 0) swap (r, s);

	if (r.x1 <= s.x1 && s.x1 <= r.x2){
		if (r.y1 <= s.y1 && s.y1 <= r.y2){
			return true;
		}
	}

	return false;
}

int hori_hori (reta r, reta s){

	if (r.angular == INF || s.angular == INF) return false;

	if (r.y1 != s.y1 && r.y2 != s.y2) return false;

	if (max (r.x2, s.x2) > r.x2) swap (r, s);

	// cout << r.x1 << ' ' << r.x2 << endl;
	// cout << s.x1 << ' ' << s.x2 << endl;

	if (s.x2 == r.x1) return 1;
	else if (s.x2 > r.x1 && (point(r) || point(s))) return 1;
	else if (s.x2 > r.x1) return 2;
	else return 0;

}


int main (){
	
	ios::sync_with_stdio(false);

	int t, x1, x2, y1, y2;
	reta r, s;

	int test = 0;

	cin >> t;

	while (t-- > 0){
		cin >> x1 >> y1 >> x2 >> y2;

		// if (test++ > 0) cout << endl;

		if (delta (x1, x2) == 0){
			r.angular = INF;
		}
		else {
			r.angular = 0;
		}

		r.x1 = min (x1, x2);
		r.x2 = max (x1, x2);
		r.y1 = min (y1, y2);
		r.y2 = max (y1, y2);

		cin >> x1 >> y1 >> x2 >> y2;

		if (delta (x1, x2) == 0){
			s.angular = INF;
		}
		else {
			s.angular = 0;
		}

		s.x1 = min (x1, x2);
		s.x2 = max (x1, x2);
		s.y1 = min (y1, y2);
		s.y2 = max (y1, y2);

		// cout << r.angular << ' ' << s.angular << endl;


		if (ver_hori (r, s)){
			cout << "POINT";
		}
		else if (hori_ver (r, s)){
			cout << "POINT";
		}
		else if (ver_ver (r, s)){
			if (ver_ver (r, s) == 1){
				cout << "POINT";
			}
			else cout << "SEGMENT";
		}
		else if (hori_hori (r, s)){
			if (hori_hori (r, s) == 1){
				cout << "POINT";
			}
			else if (hori_hori (r, s) == 2) cout << "SEGMENT";
		}
		else cout << "NO";

		cout << endl;
	}
	

	

	return 0;
}

