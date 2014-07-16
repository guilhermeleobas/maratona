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
#define CNT PI/180
#define INF 99999999
const double EPS = 1e-10;
typedef vector<vector<pair<int, int> > > graph;

int main (){

	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	while (n--){
		string s;

		cin >> s;

		int x = 0, y = 0, inc = 0;

		for (int i=0; i<s.size(); i++){
			if (s[i] == 'R')
				x++;
			else if (s[i] == 'L')
				x--;
			else if (s[i] == 'U')
				y++;
			else if (s[i] == 'D')
				y--;
			else
				inc++;
		}

		cout << x-inc << ' ' << y-inc << ' ' << x+inc << ' ' << y+inc << endl;

	}	

	

	return 0;
}
