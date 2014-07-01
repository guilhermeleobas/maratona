/*
Problema - Praça de alimentação
http://br.spoj.com/problems/PRACAALI/
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

typedef struct {
	char tipo;
	int tempo;
} cartao;

bool compare (cartao a, cartao b){
	return a.tempo < b.tempo;
}

void magic (int entrada, vector<cartao> &v){

	for (int i=0; i<v.size() && entrada; i++){
		if (v[i].tipo == '?')
			v[i].tipo = 'E',
			entrada--;
	}
}

int solver (vector<cartao> &v){
	int maximo = 0;
	int aux = 0;

	for (int i=0; i<v.size(); i++){
		if (v[i].tipo == 'E')
			aux++;
		else
			aux--;

		maximo = max (maximo, aux);
	}

	return maximo;
}

int main (){

	ios::sync_with_stdio(false);
	
	char tipo;
	string s;
	int hora, min, seg, n;
	vector<cartao> v;
	cartao c;
	int ne, nx, ns, entrada;

	while (true){
		cin >> n;

		if (!n)
			break;

		v.clear();
		v.resize (n);

		ne = 0;
		ns = 0;
		nx = 0;
		entrada = 0;

		for (int i=0; i<n; i++){
			cin >> s >> tipo;

			hora = (s[0]-48)*10 + (s[1]-48);
			min = (s[3]-48)*10 + (s[4]-48);
			seg = (s[6]-48)*10 + (s[7]-48);

			c.tempo = hora*10000 + min*100 + seg;
			c.tipo = tipo;

			v[i] = c;

			if (tipo == 'E')
				ne++;
			else if (tipo == 'X')
				ns++;
			else
				nx++;
		}

		sort (v.begin(), v.end(), compare);

/*		for (int i=0; i<v.size(); i++){
			cout << v[i].tempo << ' ' << v[i].tipo << endl;
		}
		cout << endl;*/

		if (nx == 0)
			entrada = 0;
		else if (ne > ns)
			entrada = (nx - ne + ns)/2;
		else 
			entrada = (ns - ne) + (nx - ns + ne)/2;


		magic (entrada, v);

		cout << solver(v) << endl;
		
	}

	return 0;
}
