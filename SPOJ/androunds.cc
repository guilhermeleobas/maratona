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
typedef vector<vector<pair<int, int> > > graph;

vector<int> new_segtree (int size){
	vector<int> v;

	size = log2 (size) + 1;

	v.resize (pow(2, size+1), -1);

	return v;
}

void inicializa (vector<int> &segtree, vector<int> &array, int left, int right, int node){

	if (left > right) return;

	if (left == right){
		segtree[node] = array[left];
	}
	else {
		// Compute the left and right values;
		inicializa (segtree, array, left, (left+right)/2, 2*node + 1);
		inicializa (segtree, array, (left+right)/2 + 1, right, 2*node + 2);

		// Insert the lowest value between the two childrens in the segtree[node];
/*		if (array[segtree[2*node+1]] > array[segtree[2*node+2]]){
			segtree[node] = segtree[2*node+2];
		}
		else {
			segtree[node] = segtree[2*node+1];
		}*/

		segtree[node] = segtree[2*node+1] & segtree[2*node+2];
	}
}

int query (vector<int> &segtree, vector<int> &array, int node, int left, int right, int i, int j){

	int p1, p2;

	// Se o intervalo não se intercepta;
	if (i > right || j < left){
		return -1;
	}

	// cout << "chegou aqui\n";

	// Verifica se o intervalo atual (left/right) está entre o intervalor requerido (i/j);
	if (left >= i && right <= j){
		return segtree[node];
	}

	// cout << "aqui\n";	

	// Faz a consulta para os intervalos filhos;
	p1 = query (segtree, array, 2*node+1, left, (left+right)/2, i, j);
	p2 = query (segtree, array, 2*node+2, (left+right)/2 + 1, right, i, j);

	// cout << p1 << ' ' << p2 << " com left: " << left << " e right: " << right << endl;

	if (p1 == -1) return p2;

	if (p2 == -1) return p1;

	// if (array[p1] < array[p2]) return p1;
	// else return p2;

	// cout << "Retornou pi&p2: " << p1 << ' ' << p2 <<endl;

	return p1&p2;

}

void imprime (vector<int> &segtree, vector<int> array){

	for (int cont=0; cont<segtree.size(); cont++){
		cout << segtree[cont] << ' ';
	}
	cout << endl;
}


int main (){

	int n, t, k, num;
	ios::sync_with_stdio(false);
	
	vector<int> segtree;
	vector<int> array;

	cin >> t;

	while (t-- > 0){

		cin >> n >> k;

		array.clear();
		segtree.clear();

		for (int cont=0; cont<n; cont++){
			cin >> num;
			array.push_back (num);
		}

		segtree = new_segtree(n);
		inicializa (segtree, array, 0, n-1, 0);
		// imprime (segtree, array);
		// cout << query (segtree, array, 0, 0, n-1, 4, 4) << endl;

		int a, b;
		int result;

		// cout << query (segtree, array, 0, 0, n-1, 1, 3) << endl;

		for (int i=0; i<n; i++){
			a = i-k;
			b = i+k;
			if (k >= n/2) result = query (segtree, array, 0, 0, n-1, 0, n-1);
			else if (a < 0) result = query (segtree, array, 0, 0, n-1, 0, b) & query (segtree, array, 0, 0, n-1, n+a, n-1);
			else if (b >= n) result = query (segtree, array, 0, 0, n-1, a, n-1) & query (segtree, array, 0, 0, n-1, 0, b-n);
			else result = query (segtree, array, 0, 0, n-1, a, b);
			cout << result << ' ';
		}
		cout << endl;
	}


	return 0;
}