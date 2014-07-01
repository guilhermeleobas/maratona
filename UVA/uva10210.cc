/*
Problema - Romeo and Juliet!
http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1151
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
	
	double x1, y1, x2, y2, CMD, ENF;
	double AB, result;

	while (true){
		cin >> x1 >> y1 >> x2 >> y2 >> CMD >> ENF;

		if (!cin)
			break;

		result = 0;
		AB = 0;

		AB = sqrt ( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );

		result = (1/tan (CMD * cnt) + 1/tan(ENF * cnt));

		result *= AB;

		cout << fixed << setprecision (3) << result << endl;
	}	

	

	return 0;
}
