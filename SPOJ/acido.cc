/*
Problema - Ácido Ribonucléico Alienígena
http://br.spoj.com/problems/ACIDO/
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

bool go (char a, char b){
	if ((a == 'S' && b == 'B') || (a == 'B' && b == 'S')) return true;

	if ((a == 'C' && b == 'F') || (a == 'F' && b == 'C')) return true;

	return false;
}

void find_max (string &acido){
	
	stack<char> s;
	int j_aux, i_aux, sum;
	bool flag;

	sum = 0;

	// s.push (acido[0]);

	for (int i=0; i<acido.size(); i++){
/*
		if (!s.empty()){
			cout << acido[i] << ' ' << s.top() << endl;
		}*/

		if (s.empty()){
			s.push (acido[i]);
		}
		else if (go (acido[i], s.top())){
			// cout << "Entrou aqui: " << acido[i] << ' ' << s.top() << endl;
			// i++;
			// cout << i << endl;
			s.pop();
			sum++;

		}
		else {
			s.push (acido[i]);
		}
	}

	cout << sum << endl;
}

int main (){
	
	string acido;

	while (true){
		cin >> acido;
		if (!cin) break;

		find_max (acido);
	}	

	

	return 0;
}