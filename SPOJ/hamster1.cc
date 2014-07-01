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

#define PI 3.141592653589793
#define CNT PI/180
#define INF 99999999
const double EPS = 1e-10;
typedef vector<vector<pair<int, int> > > graph;

double v, a, b;

inline double calc (double theta){
	double xm = v*v*sin(2*theta)/10;
	double ym = v*v*sin(theta)*sin(theta)/20;

	return xm*a + ym*b;
}

double angle (){
	double l = 0.0;
	double r = PI*0.5;
	double m = 0.0;

	while ( fabs (l-r) >= EPS){
		m = (l + r)/2.0;

		bool valid = fabs (r-l) > EPS;

		// cout << l << ' ' << ' ' << r << ' ' << m << ' ' << r-l << ' ' << EPS << endl;

		double cl = calc (l);
		double cr = calc (r);
		
		if (cl < cr)
			l = m;
		else
			r = m;
	}

	return m;
}

int main (){

	// ios::sync_with_stdio(false);
	
	int t;

	cin >> t;

	while (t-- > 0){

		cin >> v >> a >> b;

		double theta = 0;
		double resp = 0;

		if (b == 0){
			theta = PI/4.0;
			resp = calc (theta);
		}
		else if (a == 0){
			theta = PI/2.0;
			resp = calc (theta);
		}
		else {
			theta = angle ();
			resp = calc (theta);
		}

		theta = angle();
		resp = calc (theta);
		// cout << endl << endl;

		// cout << fixed << setprecision (3) << theta << ' ' << resp+0.00000005 << endl;
		printf ("%.3lf %.3lf\n", theta, resp);
	}



	

	return 0;
}
