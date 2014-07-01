/*
Problema - Hello Galaxy
http://www.urionlinejudge.com.br/judge/pt/problems/view/1515
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
	
	set<pair<int, string> > s;
	string planet;
	int year, t;
	int n;

	while (true){
		cin >> n;

		if (!n)
			break;

		s.clear();

		for (int i=0; i<n; i++){
			cin >> planet >> year >> t;

			s.insert (make_pair (year-t, planet));
		}

		cout << (*s.begin()).second << endl;
	}

	

	return 0;
}


