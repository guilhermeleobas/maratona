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

typedef struct Fila {
	char cmd;
	int t;
	int id;
} fila;

fila make_fila (int id, int t, char cmd){
	fila f;
	f.id = id;
	f.t = t;
	f.cmd = cmd;
	return f;
}

bool comp (fila a, fila b){

	if (a.t == b.t){
		if (a.cmd == 'e' && b.cmd == 's')
			return false;
		else if (a.cmd == 's' && b.cmd == 'e')
			return true;
	}
	
	if (a.t < b.t)
		return true;
	else
		return false;
}

bool solver (vector<fila> &v, int k){

	stack<int> s;

	s.push (v[0].id);

	for (int i = 1; i<v.size(); i++){

		if (s.size() > k)
			return false;

		if (v[i].cmd == 'e'){
			s.push (v[i].id);
		}
		else {
			if (v[i].id == s.top()){
				s.pop();
			}
			else{
				return false;
			}
		}
	}

	return true;
}

int main (){

	ios::sync_with_stdio(false);
	
	int n, k;
	vector<Fila> v;
	int x, y;

	while (true){
		cin >> n >> k;

		if (n == 0 && k == 0)
			break;

		for (int i=0; i<n; i++){
			cin >> x >> y;
			v.push_back (make_fila (i, x, 'e'));
			v.push_back (make_fila (i, y, 's'));
		}

		sort (v.begin(), v.end(), comp);

		if (solver (v, k)){
			cout << "Sim\n";
		}
		else {
			cout << "Nao\n";
		}

		v.clear();
	}
	

	

	return 0;
}
