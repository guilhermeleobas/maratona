/*
Problema - Não é mais um joguinho canadense
http://br.spoj.com/problems/CONTAGEM/
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

typedef vector<vector<int> > graph;

int main (){
	
	ios::sync_with_stdio(false);
	string s;
	long long int resp, test;

	test = 0;

	while (true){
		cin >> s;
		if (!cin) break;

		resp = 0;

		// cout << s.size() << endl;

		for (int i=0; i<s.size(); i++){
			if (s[i] == 'b'){
				resp += (long long int)pow (2, s.size() - i-1);
				// cout << resp << endl;
			}
		}
		cout << "Palavra " << ++test << endl;
		cout << resp << endl;
		cout << endl;

	}	

	

	return 0;
}
