/*
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
	
	int s1, s2, t1, t2, r1, r2;
	char aux;

	cin >> s1 >> aux >> s2 >> t1 >> aux >> t2;

	// cout << s1 << ' ' << s2 << endl << t1 << ' ' << t2 << endl;

	r2 = (s2-t2+60)%60;
	r1 = (s1-t1+24)%24;

	if (s2-t2 < 0)
		r1 = (r1+24-1)%24;


	if (r1 < 10 && r1 >=0)
		cout << '0' << r1 << ':';
	else
		cout << r1 << ':';

	if (r2 < 10)
		cout << '0' << r2 << endl;
	else
		cout << r2 << endl;

	

	return 0;
}
