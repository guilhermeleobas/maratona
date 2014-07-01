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

bool found (string &s, int i){
	if (s[i] == 'b' && s[i+1] == 'e' && s[i+2] == 'a' && s[i+3] == 'r')
		return true;

	return false;
}

void solver (string &s){
	
	int b, e; // begin, end;
	int constant = 0;
	int t = 0;

	int size = 0;

	for (int i=0; i<s.size()-3; i++){
		if (found (s, i)){
			b = i+1;
			e = i+3+1;

			int x = b-constant;
			int y = s.size()-e+1;

			// cout << x << ' ' << y << endl;

			size += x*y;
			constant = b;
		}
	}

	cout << size << endl;

}


int main (){

	ios::sync_with_stdio(false);
	
	string s;

	cin >> s;

	if (s.size() >= 4)
		solver (s);
	else
		cout << "0\n";

	return 0;
}
