/*
Problema - Miojo
http://br.spoj.com/problems/MIOJO/
Guilherme Leobas
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

int solucao (int t, int a, int b){

	for (int i = 1; i <= b; i++){
		if ((a*i)%b == t) return i;
	}
}

int main(){

	int t, a, b;

	cin >> t >> a >> b;

	int max_a;
	int max_b;

	max_a = solucao (t, a, b);
	max_b = solucao (t, b, a);

	cout << min(a*max_a, b*max_b) << endl;

	return 0;
}
