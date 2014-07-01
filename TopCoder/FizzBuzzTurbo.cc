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


class FizzBuzzTurbo {
	public:
	vector<long long> counts(long long A, long long B) {
		
		vector<long long> ans;

		long long a, b, c, d, e, f;

		a = A/3;
		b = B/3;
		if (A%3 == 0) b++;

		c = A/5;
		d = B/5;
		if (A%5 == 0) d++;

		e = A/15;
		f = B/15;
		if (A%15 == 0){
			f++;
		}

		ans.push_back (b-a-(f-e));
		ans.push_back (d-c-(f-e));
		ans.push_back (f-e);

		return ans;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
