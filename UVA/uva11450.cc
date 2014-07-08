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
#include <cstring>

using namespace std;

#define PI acos(-1)
#define CNT PI/180
#define INF 99999999
const double EPS = 1e-10;
typedef vector<vector<pair<int, int> > > graph;

int dp[21][210];
int money;

void process (int g, int stuff){

	for (int j=0; j<=money; j++)
		if (j-stuff >= 0){
			dp[g][j]  |= dp[g-1][j-stuff];
			// cout << g << ' ' << j << ' ' << dp[g][j] << endl;
		}
}

void print (int g){
	for (int i=0; i<=g; i++){
		for (int j=0; j<=money; j++){
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main(){

	int t;

	cin >> t;

	while (t--){
		int g;

		cin >> money >> g;

		memset (dp, 0, sizeof(dp));
		dp[0][0] = 1;

		// print (g);

		for (int i=1; i<=g; i++){
			int k;
			cin >> k;
			for (int j=0; j<k; j++){
				int stuff;
				cin >> stuff;
				if (stuff <= money)
					process (i, stuff);
				// print (g);
			}
			// cout << "foi\n";
			// print (g);
		}

		// print (g);

		bool valid = false;

		for (int j=money; j>=0; j--){
			if (dp[g][j]){
				valid = true;
				cout << j << endl;
				break;
			}
		}

		if (not valid)
			cout << "no solution\n";
	}




	return 0;
}
