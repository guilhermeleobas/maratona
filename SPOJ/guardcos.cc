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

double pit (int d){
	return sqrt (144 + d*d);
}

int main (){

	double d, vg, vf;
	
	while (true){
		cin >> d >> vf >> vg;

		if (!cin) break;

		if (double(12/vf) >= double(pit(d)/vg)){
			cout << "S\n";
		}
		else {
			cout << "N\n";
		}
	}
	
	

	

	return 0;
}