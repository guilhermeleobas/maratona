/*
Problema - Testing the catcher
http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=167
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

using namespace std;

void imprime (multiset<int> s){

	for (multiset<int>::iterator it = s.begin(); it != s.end(); it++){
		cout << *it << ' ';
	}
	cout << endl;
}

int main (){
	
	vector<int> v;
	vector<int> sum;
	int num, m, test;
	bool flag = false;

	test = 0;

	while (scanf ("%d", &num) && num != -1){

		v.clear();
		sum.clear();
		m = 0;

		if (flag) cout << endl;

		v.push_back (num);

		while (scanf ("%d", &num) && num != -1){
			v.push_back (num);
		}


		sum.resize (v.size(), 1);

		for (int i=0; i<v.size(); i++){
			// sum[i] = 1;
			for (int j=0; j<i; j++){
				if (v[j] >= v[i]){
					sum[i] = max(sum[i], sum[j]+1);
				}

				m = max (m, sum[i]);
			}
		}

		cout << "Test #" << ++test << ":\n  maximum possible interceptions: ";
		cout << m << endl;

		flag = true;
	}


	return 0;
}