/*
Problema - 11385 - Da Vinci Code
http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2380
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

	set<long long int> s;
	long long int ant1, ant2, next, aux;
	int t, n;
	vector<long long int> v;
	map<long long int, string> m;
	map<long long int, string>::iterator it;
	string word;
	int lim;
	long long int maximo;

	s.insert (1);
	s.insert (2);

	ant1 = 1;
	ant2 = 2;

	for (int cont=0; cont<46; cont++){
		next = ant1 + ant2;
		s.insert (next);
		ant1 = ant2;
		ant2 = next;
	}

	cin >> t;
	while (t-- > 0){
		cin >> n;
		m.clear();
		v.clear();
		word.clear();

		maximo = 0;

		for (int cont=0; cont<n; cont++){
			cin >> aux;
			if (s.find (aux) != s.end()){
				v.push_back (aux);
				m.insert (make_pair (aux, " "));
				if (aux > maximo){
					maximo = aux;
				}
			}
		}

		getline (cin, word);
		getline (cin, word);

		aux = 0;
		lim = 0;

		for (int i=0; i<word.size() && lim < v.size(); i++){
			if (word[i] >= 'A' && word[i] <= 'Z'){
				m[v[i-aux]] = word[i];
				lim++;
			}
			else {
				aux++;
			}
		}

		for (set<long long int>::iterator sit = s.begin(); sit != s.end() && *sit <= maximo; sit++){
			it = m.find (*sit);
			if (it != m.end()){
				cout << it->second;
			}
			else {
				cout << ' ';
			}
		}
		cout << endl;
	}


	return 0;
}