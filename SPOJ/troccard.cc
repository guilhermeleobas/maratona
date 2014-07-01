/*
Problema - Troca cartas;
http://br.spoj.com/problems/TROCCARD/
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
#define INF 100010
typedef vector<vector<pair<int, int> > > graph;

int main (){

	ios::sync_with_stdio(false);
	
	vector<bool> alice, beatriz;
	int t1, t2, a, b, carta;

	while (true){
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;

		alice.clear();
		beatriz.clear();
		alice.resize (INF, 0);
		beatriz.resize (INF, 0);

		t1 = 0;
		t2 = 0;

		for (int i=0; i<a; i++){
			cin >> carta;
			alice[carta] = true;
		}

		for (int i=0; i<b; i++){
			cin >> carta;
			beatriz[carta] = true;
		}

		for (int i=0; i<INF; i++){
			if (!alice[i] && beatriz[i])
				t1++;
			if (alice[i] && !beatriz[i])
				t2++;
		}

		cout << min(t1, t2) << endl;
	}
	

	

	return 0;
}

