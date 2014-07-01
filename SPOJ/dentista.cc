/*
Problema - Dentista
http://br.spoj.com/problems/JDENTIST/
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


void func (vector<pair<int, int> > &v){

	int start, end, cnt, atual;

	atual = v.size()-1;
	cnt = 1;

	for (int cont=v.size()-2; cont >= 0; cont--){
		if (v[atual].first >= v[cont].second){
			// cout << v[atual].first << ' ' << v[atual].second << " - " << v[cont].first << ' ' << v[cont].second << endl;
			cnt++;
			atual = cont;
		}
	}

	cout << cnt <<endl;
}

void imprime (vector<pair<int, int> > v){
	for (int cont=v.size()-1; cont>=0; cont--){
		cout << v[cont].first << ' ' << v[cont].second << endl;
	}
}

int main (){
	
	vector<pair<int, int> > v;
	int n, start, end;

	ios::sync_with_stdio(false);

	cin >> n;

	for (int cont=0; cont<n; cont++){
		// cin >> start >> end;
		scanf ("%d%d", &start, &end);
		v.push_back (make_pair (start, end));
	}	

	// sort (v.begin(), v.end(), compare);

	// imprime (v);

	func (v);

	

	return 0;
}