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


class WhichDay {
	public:
	string getDay(vector <string> notOnThisDay) {
		map<string, int> m;

		m["Sunday"] = 0;
		m["Monday"] = 0;
		m["Tuesday"] = 0;
		m["Wednesday"] = 0;
		m["Thursday"] = 0;
		m["Friday"] = 0;
		m["Saturday"] = 0;

		for (int i=0; i<notOnThisDay.size(); i++){
			m[notOnThisDay[i]] = 1;
		}

		for (map<string,int>::iterator it = m.begin(); it != m.end(); it++){
			if (it->second == 0)
				return it->first;
		}
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
