/*
Problema - CONTA1
http://br.spoj.com/problems/CONTA1/
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
	
	int consumo, total;

	total = 0;

	cin >> consumo;

	if (consumo > 100){
		total += (consumo-100)*5;
		consumo = 100;
	}

	if (consumo > 30){
		total += (consumo-30)*2;
		consumo = 30;
	}

	if (consumo > 10){
		total += (consumo-10);
	}

	total += 7;

	cout << total << endl;

	return 0;
}
