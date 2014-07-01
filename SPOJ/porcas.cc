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
	
	int n, p, x, y;
	vector<int> v;

	while (true){
		cin >> n;
		if (!cin)
			break;

		for (int i=0; i<n; i++){
			cin >> x >> y;

			for (int j=x; j<=y; j++){
				v.push_back (j);
			}
		}

		sort (v.begin(), v.end());

		cin >> p;

		vector<int>::iterator lower = lower_bound (v.begin(), v.end(), p);
		vector<int>::iterator upper = upper_bound (v.begin(), v.end(), p);

		if (lower == upper){
			cout << p << " not found\n";
		}
		else {
			cout << p << " found from " << lower-v.begin() << " to " << upper-v.begin()-1 << endl;
		}

		v.clear();
	}



	

	return 0;
}
