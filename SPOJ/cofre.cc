/*
Problema - COFRE
http://br.spoj.com/problems/COFRE/
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
	
	int test = 0;
	int n, a, b, j, z;

	while (true){
		cin >> n;
		if (n == 0)
			break;

		j = 0;
		z = 0;

		cout << "Teste " << ++test << endl;
		while (n-- > 0){
			cin >> a >> b;
			j += a;
			z += b;
			cout << j-z << endl;
		}
		cout << endl;
	}	

	return 0;
}
