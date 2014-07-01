/*
	Playing with Dice - Codeforces Div. 2 round #222 = http://codeforces.com/contest/378/problem/A
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
	
	int a, b;
	int a_win, b_win, draw;

	cin >> a >> b;

	draw = 0;
	a_win = 0;
	b_win = 0;

	for (int i=1; i<=6; i++){
		if (abs(a-i) == abs(b-i)){
			draw++;
		}
		else if (abs(a-i) < abs(b-i)){
			a_win++;
		}
		else {
			b_win++;
		}
	}	

	cout << a_win << ' ' << draw << ' ' << b_win << endl;

	return 0;
}
