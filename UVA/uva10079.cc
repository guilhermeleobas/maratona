/*
Problema - Pizza Cutting
http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1020
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

long long f (long long n){
	return ((n*n + n) /2 + 1);
}

int main (){

	ios::sync_with_stdio(false);
	
	long long n;

	while (true){
		cin >> n;

		if (n < 0)
			break;

		cout << f(n) << endl;
	}	

	

	return 0;
}
