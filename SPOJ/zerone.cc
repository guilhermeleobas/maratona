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
	string s;
	int consultas, i, j;
	int test = 0;

	while (true){
		s.clear();
		cin >> s;

		if (!cin) break;

		v.clear();
		v.resize (s.size(), 0);

		v[0] = 0;

		for (int cont=1; cont<s.size(); cont++){
			if (s[cont] == s[cont-1]) v[cont] = v[cont-1];
			else v[cont] = v[cont-1] + 1;
		}

		cin >> consultas;

		cout << "Case " << ++test << ":" << endl;

		for (int cont=0; cont<consultas; cont++){
			cin >> i >> j;

			if (v[i] == v[j]) cout << "Yes\n";
			else cout << "No\n";
		}
	}	

	

	return 0;
}