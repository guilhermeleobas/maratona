/*
	Codeforces GoodBye 2013
	http://codeforces.com/contest/379/problem/A
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
	
	int a, b, resto;
	int result;
	resto = 0;

	cin >> a >> b;

	// result = a;
	result = 0;

	while (a > 0){
		a--;
		result += 1;
		resto++;
		if (resto >= b){
			a++;
			resto = 0;
		}
	}

	cout << result << endl;

	return 0;
}
