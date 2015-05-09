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

#define PI acos(-1)
#define cnt PI/180
#define inf 99999999

void imprime (vector<vector<int> > &v){
	for (int i=0; i<v.size(); i++){
		for (int j=0; j<v.size(); j++){
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int bfs (vector<vector<int> > &c, vector<vector<int> > &f, int source, int synk){

	queue<int> q;
	vector<int> veio;
	int atual, next;

	veio.resize (c.size(), -1);

	q.push (source);

	veio[source] = -2;

	while(!q.empty()){
		atual = q.front();
		q.pop();

		for (int i=0; i<c.size(); i++){
			if (veio[i] == -1 && (c[atual][i] - f[atual][i] > 0)){
				veio[i] = atual;
				q.push (i);
			}
		}
	}

	int cap = inf;
	int prev;
	next = synk;

	while (veio[next] >= 0){
		prev = veio[next];
		cap = min (cap, c[prev][next]-f[prev][next]);
		next = prev;
	}

	next = synk;

	while (veio[next] >= 0){
		prev = veio[next];
		f[prev][next] += cap;
		f[next][prev] -= cap;
		next = prev;
	}

	if (cap == inf) return 0;

	// cout << "cap: " << cap << endl;

	return cap;
}

void maxflow (vector<vector<int> > &c, vector<vector<int> > &f, int source, int synk){

	while (bfs (c, f, source, synk)){

	}

	// cout << endl;

	// bfs (c, f, source, synk);
	// bfs (c, f, source, synk);
}

pair<int, int> calc_dist (vector<vector<int> > &c, vector<vector<int> > &f, int source, int synk){

	queue<int> q;
	vector<int> dist, veio, v; 
	int i;
	dist.resize (c.size(), inf);
	veio.resize (c.size(), -1);
	v.resize (c.size(), 0);

	q.push (source);
	dist[source] = 0;

	while (!q.empty() && v[synk] == 0){

		i = q.front();
		q.pop();

		if (i == synk) break;

		// cout << "I: " << i+1 << endl;

		for (int j=0; j<v.size(); j++){
			if (v[j] == 0 && f[i][j] > 0){
				// cout << "j: " << j+1 << endl;
				q.push(j);
				v[j] = 1;
				dist[j] = dist[i]+1;
				veio[j] = i;
			}
		}
	}

	// cout << endl;

	if (v[synk] == 0) return make_pair (0, 0);

	int where, prev;
	int cap = inf;

	where = synk;

	while (veio[where] >= 0){
		prev = veio[where];
		cap = min (cap, f[prev][where]);
		where = prev;
	}

	where = synk;

	while (veio[where] >= 0){
		prev = veio[where];
		f[prev][where] -= cap;
		f[where][prev] += cap;
		where = prev;
	}

	if (dist[synk] == inf) return make_pair (0, 0);

	return make_pair (dist[synk], cap);
}



int main (){
	
	vector<vector<int> > f;
	vector<vector<int> > c;
	int n, m, a, x, y, custo;

	int cont = 0;

	while (true){
		cin >> n >> m >> a;

		if (n == 0 && m == 0 && a == 0) break;

		f.clear();
		c.clear();

		f.resize (n, vector<int> (n, 0));
		c.resize (n, vector<int> (n, 0));

		for (int i=0; i<m; i++){
			cin >> x >> y >> custo;
			x--;
			y--;
			c[x][y] = custo;
		}

		maxflow (c, f, 0, f.size()-1);

		// imprime (f);

		vector<int> resposta;
		resposta.clear();
		resposta.resize (1024, 0);

		while (true){
			pair<int, int> cont = calc_dist (c, f, 0, n-1);
			if (cont.first == 0) break;

			resposta[cont.first] += cont.second;
		}

		int d=0;
		for (d=1; a>0; d++){
			resposta[d] += resposta[d-1];
			a-=resposta[d];
		}

		cout << d-1 << endl;
		

		// calc_dist (c, f, 0, n-1);
		// calc_dist (c, f, 0, n-1);

		// bfs (v, 0, v.size()-1);
	}
	

	

	return 0;
}