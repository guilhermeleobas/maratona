//Link: http://codeforces.com/problemset/problem/242/C

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

using namespace std;

#define max 100000

typedef vector<int> adj;
typedef map<int, adj> row;
typedef long long int num;
typedef pair<num, num> par;

void imprime (row g){

	row::iterator it;

	for (it = g.begin(); it != g.end(); it++){
		cout << it->first << ": ";
		// cout << it->second[1] << endl;
		for (int i=0; i<it->second.size(); i++){
			cout << it->second[i] << ' ';
		}
		cout << endl;
	}
}

void dijkstra (row g, num sz, par start, par end){

	queue<par> fila;
	map<int, par> peso;
	par atual;
	row::iterator it;

	fila.push (start);

	while (!fila.empty()){

		atual = fila.front();
		fila.pop();

		if (atual == end){
			break;
		}

		if (g.find (atual.first) != g.end()){

		}


	}

}

int main (){

	row g;
	row::iterator it;
	num x0, y0, x1, y1;
	num r, a, b, sz;
	vector<int> space, alt;
	int n;

	cin >> x0 >> y0 >> x1 >> y1;
	cin >> n;

	for (int cont=0; cont<n; cont++){
		cin >> r >> a >> b;
		space.clear();
		for (int i=a; i<=b; i++){
			space.push_back (i);
		}

		it = g.find(r);

		if (it != g.end()){
			alt = it->second;
			g.erase (it);
			space.insert (space.end(), alt.begin(), alt.end());

		}
		g.insert (make_pair <int, adj> (r, space));
	}

	sz = 0;
	for (it = g.begin(); it != g.end(); it++){
		sz += it->second.size();
	}

	cout << g[3][9] << endl;
	imprime (g);


	return 0;
}