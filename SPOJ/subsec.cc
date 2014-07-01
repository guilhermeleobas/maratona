/*
Problema - Counting Subsequences
http://www.spoj.com/problems/SUBSEQ/
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

int main (){

	ios::sync_with_stdio(false);

	int test, n, num;
	long long resp, soma;
	map<long long, long long> m;

	cin >> test;

	while (test-- > 0){

		cin >> n;

		resp = 0;
		soma = 0;

		m.clear();

		m[0] = 1;

		while (n-- > 0){
			cin >> num;
			soma += num;
			resp += m[soma-47];
			m[soma]++;
		}
		cout << resp << endl;

	}



  return 0;
}
