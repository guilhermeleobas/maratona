/*

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

// ax + by = t
// ax = 1 mod b
// Basta substituir t por 1;
int inv (int t, int a, int b){

	for (int i = 1; i <= b; i++){
		if ((a*i)%b == t) return i;
	}
}

int solve (vector<int> a, vector<int> b){

	int B = 1;
	vector<int> r (3, 0);

	for (int i=0; i<3; i++)
		B *= b[i];

	for (int i=0; i<3; i++)
		r[i] = inv (1, B/b[i], b[i]);

	int resp = 0;

	for (int i=0; i<3; i++){
		resp += (B/b[i])*a[i]*r[i];
		resp = (resp + B)%B;
	}

	return resp;
}

int main (){

	ios::sync_with_stdio(false);
	
	vector<int> a;
	vector<int> b;

	b.push_back (23);
	b.push_back (28);
	b.push_back (33);

	a.resize (3, 0);

	int x, y, z, d, test = 0;

	while (true){
		cin >> x >> y >> z >> d;

		if (x == -1 && y == -1 && z == -1 && d == -1)
			break;

		a[0] = x%23;
		a[1] = y%28;
		a[2] = z%33;

		int resp = solve (a, b);
		resp = (resp-d+21252)%21252;

		if (resp == d)
			resp += 21252;

		cout << "Case " << ++test << ": the next triple peak occurs in " << resp << " days.\n";

	}

	

	return 0;
}
