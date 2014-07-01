/*
Problema - Caça ao tesouro - Subset sum
http://br.spoj.com/problems/TESOURO/
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

bool subset (vector<int> &v, int c){

	int n = v.size();
	bool subset[n+1][c+1];

	subset[0][0] = true;

	for (int i=1; i <= c; i++)
		subset[0][i] = false;

	for (int i=1; i<=n; i++){
		for (int j=0; j<c+1; j++){
			if (v[i-1] > j)
				subset[i][j] = subset[i-1][j];
			else
				subset[i][j] = (subset[i-1][j] || subset[i-1][j-v[i-1]]);
		}
	}


	return subset[n][c];
}

int main (){

	ios::sync_with_stdio(false);

	int x, y, n, sum, result, test = 0;
	vector<int> v;

	while (true){
		cin >> x >> y >> n;

		if (x == 0 && y == 0 && n == 0)
			break;

		v.clear();
		v.resize (n, 0);
		sum = 0;

		for (int i=0; i<n; i++){
			cin >> v[i];
			sum += v[i];
		}

		sum += abs(y-x);

		cout << "Teste " << ++test << endl;
		if (sum < 0)
			goto loop;
		else if (sum % 2 != 0)
			cout << "N\n\n";
		else if (sum == 0 || subset (v, sum/2))
			cout << "S\n\n";
		else
			cout << "N\n\n";

		loop:
		while (true){

		}
	}

	return 0;
}
