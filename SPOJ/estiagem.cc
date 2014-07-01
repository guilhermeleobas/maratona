/*
	http://www.urionlinejudge.com.br/repository/UOJ_1023.html
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
	map<int, int> m;
	map<int, int>::iterator it;
	int test = 0;
	int n, x, y, sum;
	int cont;
	float average;

	while (true){
		cin >> n;
		if (n == 0) break;

		if (test) cout << endl;
 
		sum = 0;
		average = 0;
		m.clear();

 		for (int i=0; i<n; i++){
			cin >> x >> y;
			sum += x;
			average += y;
			m[y/x] += x;
		}
		
		cont = 0;
		cout << "Cidade# " << ++test << ":\n";
		for (it = m.begin(); it != m.end(); it++)
		{
			cout << it->second << '-' << it->first;
			if (++it != m.end()) cout << ' ';
			it--;
		}
		cout << endl;
		cout << "Consumo medio: " << fixed << setprecision(2) << float (average/sum)-0.0049999999 << " m3.\n";
	}
	return 0;
}
