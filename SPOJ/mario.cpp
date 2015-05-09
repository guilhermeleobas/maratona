/*
Problema - Mario
http://br.spoj.com/problems/MARIO/
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
	
	vector<int> v;
	int n, l, posi, maior;

	while (true){
		cin >> n >> l;
		if (!n && !l)
			break;

		v.clear();
		v.resize (l, 0);
		maior = 0;

		for (int i=0; i<l; i++)
			cin >> v[i];

		for (int i=0; i<l; i++){
			posi = upper_bound (v.begin(), v.end(), v[i]+n-1) - v.begin();
			maior = max (posi-i, maior);
		}

		cout << n-maior << endl;
	}	

	return 0;
}

