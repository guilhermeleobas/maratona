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

int main (){

	ios::sync_with_stdio(false);
	
	int k, a, b, v, cont = 0;

	cin >> k >> a >> b >> v;

	while (a > 0){

		if (b >= k-1){
			b -= k-1;
			a -= (k)*v;
			cont++;
		}
		else if (b > 0){
			a -= (b+1)*v;
			b = 0;
			cont++;
		}
		else {
			a -= v;
			cont++;
		}
	}
	
	cout << cont << endl;
	

	return 0;
}
