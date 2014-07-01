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


class CircleMarket {
	public:
	int makePurchases(vector <int> openTime, vector <int> closeTime, int travelTime) {
		int count = 0;
		int n = openTime.size();
		vector<bool> valid (n, false);
		bool go = false;
		int buy = 0;
		while (true){
			go = false;
			for (int i=0; i<n; i++){
				if (!valid[i] && count >= openTime[i] && count <= closeTime[i]){
					valid[i] = true;
					buy++;
				}
				if (count <= closeTime[i])
					go = true;
				count += travelTime;
			}
			
			if (!go)
				break;
		}
		
		return buy;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
