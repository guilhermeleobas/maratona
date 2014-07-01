/*
Problema - Impedido
http://br.spoj.com/problems/IMPEDIDO/
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
	
	int a, d;
	vector<int> atacantes, defensores;

	while (true){
		cin >> a >> d;
		if (!a && !d)
			break;

		atacantes.clear();
		atacantes.resize (a);
		defensores.clear();
		defensores.resize (d);

		for (int i=0; i<a; i++)
			cin >> atacantes[i];

		for (int i=0; i<d; i++)
			cin >> defensores[i];

		sort (atacantes.begin(), atacantes.end());
		sort (defensores.begin(), defensores.end());

		if (atacantes[0] < defensores[1])
			cout << "Y\n";
		else
			cout << "N\n";
	}

	

	return 0;
}
