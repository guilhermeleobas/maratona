#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>

using namespace std;

#define inf 9999999

typedef struct {
	int vertex;
	int from;
	int priority;
} pq;

bool operator < (pq a, pq b){
	return a.priority < b.priority;
}

bool operator > (pq a, pq b){
	return a.priority > b.priority;
}

bool operator == (pq a, pq b){
	return a.priority = b.priority;
}

int converte (char c){
	if (c > 'Z'){
		return c-'a'+26;
	}

	return c-'A';
}

void imprime (vector<vector<int> > &v){
	for (int i=0; i<v.size(); i++){
		for (int j=0; j<v.size(); j++){
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}

	cout << endl << endl;
}

int pfs (vector<vector<int> > &v, int start, int end){

	priority_queue<pq> priority;
	pq next, atual;
	vector<int> visited (v.size(), -1);
	vector<int> veio (v.size(), -1);
	int cap = 0;

	atual.vertex = start;
	atual.from = -1;
	atual.priority = inf;
	priority.push (atual);
	int where, prev;


	while (!priority.empty()){
	
		atual = priority.top();
		priority.pop();

		// cout << "visitou: " << atual.vertex << endl;

		if (visited[atual.vertex] != -1) continue;

		veio[atual.vertex] = atual.from;

		if (atual.vertex == end){
			cap = atual.priority;
			break;
		}

		visited[atual.vertex] = 1;

		for (int i=0; i<v.size(); i++){
			if (v[atual.vertex][i] > 0){
				next.priority = min (atual.priority, v[atual.vertex][i]);
				next.vertex = i;
				next.from = atual.vertex;
				priority.push (next);
			}
		}
	}

	where = end;

	while (veio[where] > -1){
		prev = veio[where];
		v[prev][where] -= cap;
		v[where][prev] += cap;
		where = prev;
	}

	// cout << "retornou: " << cap << endl;
	return cap;

}

int max_flow (vector<vector<int> > &v, int start, int end){

	int result = 0;
	int path_cap = 0;

	while (true){
		path_cap = pfs (v, start, end);
		if (path_cap == 0) break;
		else result += path_cap;
	}

	return result;
}


int main (){

	ios::sync_with_stdio(false);

	vector<vector<int> > v;
	int n, m, c, sup;
	int cavalo, humano;
	int test = 0;

	while (true){
		cin >> n >> m >> c;

		if (!cin) break;

		v.clear();

		v.resize (n+m+3, vector<int> (n+m+3, 0));

		for (int i=0; i<n; i++){
			cin >> sup;
			v[m+i+1][n+m+1] = sup;
			// v[n+m+1][m+i+1] = sup;
		}

		// imprime (v);

		for (int i=0; i<c; i++){
			cin >> cavalo >> humano;
			// v[cavalo+m][humano] = 1;
			v[humano][cavalo+m] = 1;
		}

		// imprime (v);

		for (int i=0; i<m; i++){
			v[0][i+1]=1;
			// v[i+1][0]=1;
		}

		// imprime (v);


		cout << "Instancia " << ++test << endl << min (m, max_flow (v, 0, n+m+1)) << endl << endl;
	}




	return 0;
}
