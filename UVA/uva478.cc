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
const double EPS = 1e-10;
typedef vector<vector<pair<int, int> > > graph;

int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
	double x, y;

	int cmp(point q) const {
		if (int t = ::cmp(x, q.x)) return t;
		return ::cmp(y, q.y);
	}

	bool operator ==(point q) const { return cmp(q) == 0; }
	bool operator !=(point q) const { return cmp(q) != 0; }
	bool operator < (point q) const { return cmp(q) < 0; }
};

struct figure {

	char type;

	point p1, p2, p3, center;
	double raio;

	double area (point p1, point p2, point p3){
		return fabs((p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y)+ p3.x*(p1.y-p2.y))/2.0);
	}

	double dist_point (point a, point b){
		double result = 0;

		result = ((a.x-b.x)*(a.x-b.x)) + ((a.y-b.y)*(a.y-b.y));

		return sqrt(result);
	}

	bool inside (point p){

		if (type == 'r'){

			if (p == p1 || p == p2)
				return false;

			if (p.x > (double) p1.x && p.x < (double) p2.x){
				if (p.y > (double) p2.y && p.y < (double) p1.y){
					return true;
				}
			}

			return false;
		}
		else if (type == 'c'){
			if (dist_point (center, p) < (double)raio)
				return true;
			else
				return false;
		}
		else {

			if (p == p1 || p == p2 || p == p3)
				return false;

			// cout << "aaa\n";

			double A = area (p1, p2, p3);
			double A2 = area (p, p2, p3);
			double A3 = area (p1, p, p3);
			double A4 = area (p1, p2, p);

			// cout << A << ' ' << A2 << ' ' << A3 << ' ' << A4 << '=' << A2+A3+A4 << endl;

			return (fabs(A - (A2 + A3 + A4)) <= EPS);
		}
	}
};


void imprime (vector<struct figure> &v, int quant){
	for (int i=0; i<quant; i++)
		cout << v[i].type << endl;
	cout << endl;
}

int main (){

	ios::sync_with_stdio(false);
	
	int quant = 0;
	char type;
	vector<struct figure> v (15);
	point p;
	int count = 0;
	bool sync = false;

	while (true){
		cin >> type;

		if (type == '*')
			break;

		if (type == 'r'){
			v[quant].type = type;
			cin >> v[quant].p1.x >> v[quant].p1.y >> v[quant].p2.x >> v[quant].p2.y;
		}
		else if (type == 'c'){
			v[quant].type = type;
			cin >> v[quant].center.x >> v[quant].center.y >> v[quant].raio;
		}
		else {
			v[quant].type = type;
			cin >> v[quant].p1.x >> v[quant].p1.y >> v[quant].p2.x >> v[quant].p2.y >> v[quant].p3.x >> v[quant].p3.y;
		}

		quant++;	
	}

	while (true){
		count++;
		sync = false;
		cin >> p.x >> p.y;

		// cout << p.x << ' ' << p.y << endl;

		if (p.x == double(9999.9) && p.y == double (9999.9))
			break;

		for (int i=0; i<quant; i++){
			if (v[i].inside (p)){
				cout << "Point " << count << " is contained in figure " << i+1 << "\n";
				sync = true;
			}
		}

		if (!sync)
			cout << "Point " << count << " is not contained in any figure\n";


	}
	

	return 0;
}
