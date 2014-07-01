/*
Problema - Let me count the ways
http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=293
Guilherme Leobas
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
#include <functional>
#include <map>
#include <utility>
#include <deque>
#include <iomanip>

using namespace std;

long long int vetor[7][30050];

long long int query (int moeda){
	return vetor[5][moeda];
}

int main (){

	ios::sync_with_stdio(false);

	int n;
	vector<int> v;

	v.push_back (0);
	v.push_back (1);
	v.push_back (5);
	v.push_back (10);
	v.push_back (25);
	v.push_back (50);

	for (int i=0; i<v.size(); i++){
		vetor[i][0] = 1;
	}

	for (int j=0; j<30010; j++){
		vetor[0][j] = 0;
	}

	for (int i=1; i<v.size(); i++){
		for (int j=1; j<30010; j++){
			if (j < v[i]){
				vetor[i][j] = vetor[i-1][j];
			}
			else vetor[i][j] = vetor[i][j-v[i]] + vetor[i-1][j];
		}
	}

	while (true){
		cin >> n;
		if (!cin) break;

		if (query(n) == 1){
			cout << "There is only " << query(n) << " way to produce " << n << " cents change.\n";
		}
		else cout << "There are " << query(n) << " ways to produce " << n << " cents change.\n";
	}

  return 0;
}