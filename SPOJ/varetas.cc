/*
Problema - Varetas
http://br.spoj.com/problems/VARETAS/
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
	
	int n, tam, quant, total;
	vector<int> v;

	while (true){
		cin >> n;
		if (n == 0)
			break;

		total = 0;

		while (n-- > 0){
			cin >> tam >> quant;
			total += quant/2;
		}

		cout << total/2 << endl;
	}	

	

	return 0;
}
