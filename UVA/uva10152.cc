/*
UVA problem 10152 - Shellsort
http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1093
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
	
	vector<string> start, end;
	vector<int> v;
	map<string, int> m;
	int t, n;
	string s;

	cin >> t;

	while (t-- > 0){

		start.clear();
		end.clear();
		m.clear();
		v.clear();

		cin >> n;

		getline (cin, s);

		// Ordem inicial;
		for (int i=0; i<n; i++){
			getline (cin, s);
			start.push_back (s);
		}

		// Ordem desejada;
		for (int i=0; i<n; i++){
			getline (cin, s);
			end.push_back (s);
			m[s] = i;
		}

		// Escreve a ordem desejada já mapeada;
		for (int i=0; i<n; i++)
			v.push_back (m[start[i]]);

		int desired = -1, biggest = -1;

		for (int i=0; i<n; i++){
			if (v[i] > desired)
				desired = v[i];
			else if (v[i] > biggest)
				biggest = v[i];
		}

		for (int i=biggest; i>=0; i--)
			cout << end[i] << endl;
		cout << endl;

		
	}	

	

	return 0;
}
