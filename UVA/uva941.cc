/*
Problema - 941 - Permutations
http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=882
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

using namespace std;

typedef vector<vector<pair<int, int> > > graph;

int main (){
	
	ios::sync_with_stdio(false);

	long long int fatorial = 1;
	long long int aux;
	long long int calc, n;
	int sz;
	vector<long long int> fat;
	string s;
	int t;

	fat.push_back (1);

	for (int cont=1; cont<=20; cont++){
		
		fatorial *= cont;
		fat.push_back (fatorial);
		// cout << fatorial << ' ' << fac.back() << endl;
	}

	cin >> t;

	while (t-- > 0){
		cin >> s >> n;

		sort (s.begin(), s.end());

		while (!s.empty()){
			
			sz = s.size() - 1;

			calc = n / fat[sz];

			cout << s[calc];
			s.erase (s.begin() + calc);

			n  = n - calc*fat[sz];


		}
		

		cout << endl;
	}

	return 0;
}