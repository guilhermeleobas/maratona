/*
Problema - Banco do farao
http://br.spoj.com/problems/BANFARAO/
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
#define inv -100000
typedef vector<vector<pair<int, int> > > graph;

typedef struct No {
	int size;
	int sum;
	int size_l;
	int sum_l;
	int size_r;
	int sum_r;
	int max_size;
	int max_sum;
}no;

void imprime_no (no n){
	cout << "Size: " << n.size << endl;
	cout << "Sum: " << n.sum << endl;
	cout << "Size_l: " << n.size_l << endl;
	cout << "Sum_l: " << n.sum_l << endl;
	cout << "size_r: " << n.size_r << endl;
	cout << "sum_r: " << n.sum_r << endl;
	cout << "Max_sum: " << n.max_sum << endl;
	cout << "Max_size: " << n.max_size << endl;
}

No join (No a, No b){

	no aux;

	if (a.size == -1)
		return b;
	if (b.size == -1)
		return a;

	aux.size = a.size + b.size;
	aux.sum = a.sum + b.sum;

	aux.sum_l = -INF;
	aux.size_l = -INF;

	if (aux.sum_l < a.sum){
		aux.sum_l = a.sum;
		aux.size_l = a.size;
	}

	if (aux.sum_l < a.sum_l){
		aux.sum_l = a.sum_l;
		aux.size_l = a.size_l;
	}

	if (aux.sum_l < (a.sum+b.sum_l)){
		aux.sum_l = a.sum + b.sum_l;
		aux.size_l = a.size + b.size_l;
	}

	if (aux.sum_l == (a.sum+b.sum_l)){
		aux.size_l = max (aux.size_l, a.size+b.size_l);
	}

	if (aux.sum_l == a.sum_l){
		aux.size_l = max (aux.size_l, a.size_l);
	}

	if (aux.sum_l == a.sum){
		aux.size_l = max (aux.size_l, a.size);
	}

	aux.sum_r = -INF;
	aux.size_r = -INF;

	if (aux.sum_r < b.sum){
		aux.sum_r = b.sum;
		aux.size_r = b.size;
	}

	if (aux.sum_r < b.sum_r){
		aux.sum_r = b.sum_r;
		aux.size_r = b.size_r;
	}

	if (aux.sum_r < (b.sum+a.sum_r)){
		aux.sum_r = b.sum+a.sum_r;
		aux.size_r = b.size + a.size_r;
	}

	if (aux.sum_r == (b.sum+a.sum_r)){
		aux.size_r = max (aux.size_r, b.size+a.size_r);
	}

	if (aux.sum_r == b.sum_r){
		aux.size_r = max (aux.size_r, b.size_r);
	}

	if (aux.sum_r == b.sum){
		aux.size_r = max (aux.size_r, b.size);
	}

	aux.max_sum = -INF;
	aux.max_size = -INF;

	// filho a esquerda;
	if (a.max_sum > aux.max_sum){
		aux.max_sum = a.max_sum;
		aux.max_size = a.max_size;
	}
	else if (a.max_sum == aux.max_sum){
		aux.max_size = max (aux.max_size, a.max_size);
	}

	// filho a direita;
	if (b.max_sum > aux.max_sum){
		aux.max_sum = b.max_sum;
		aux.max_size = b.max_size;
	}
	else if (b.max_sum == aux.max_sum){
		aux.max_size = max (aux.max_size, b.max_size);
	}

	// 
	if (aux.max_sum < (b.sum+a.sum_r)){
		aux.max_sum = b.sum + a.sum_r;
		aux.max_size = b.size + a.size_r;
	}
	else if (aux.max_sum == (b.sum + a.sum_r)){
		aux.max_size = max (b.size+a.size_r, aux.max_size);
	}

	// 
	if (aux.max_sum < (a.sum + b.sum_l)){
		aux.max_sum = a.sum + b.sum_l;
		aux.max_size = a.size + b.size_l;
	}
	else if (aux.max_sum == (a.sum + b.sum_l)){
		aux.max_size = max (a.size+b.size_l, aux.max_size);
	}

	// Intervalo no meio
	if (aux.max_sum < (a.sum_r + b.sum_l)){
		aux.max_sum = a.sum_r + b.sum_l;
		aux.max_size = a.size_r + b.size_l;
	}
	else if (aux.max_sum == (a.sum_r + b.sum_l)){
		aux.max_size = max (aux.max_size, (a.size_r + b.size_l));
	}

	// Soma dos filhos;
	if (aux.max_sum < aux.sum){
		aux.max_sum = aux.sum;
		aux.max_size = aux.size;
	}
	else if (aux.max_sum == aux.sum){
		aux.max_size = max (aux.max_size, aux.size);
	}

	return aux;
}

no segtree[300010];
int vetor[100100];
    
void inicializa (int node, int l, int r){

	no aux;

    if (l > r) return;

    if (l == r){
    	aux.size = 1;
    	aux.size_l = 1;
    	aux.size_r = 1;
    	aux.max_size = 1;
    	aux.sum = vetor[r];
    	aux.sum_l = vetor[r];
    	aux.sum_r = vetor[r];
    	aux.max_sum = vetor[r];
        segtree[node] = aux;
    }
    else {
        inicializa (2*node+1, l, (l+r)/2);
        inicializa (2*node+2, (l+r)/2+1, r);

     //    cout << "\n\nQuery de nos:" << node << "\n\n";
	    // cout << "No p1:\n";
	    // imprime_no (segtree[2*node+1]);
	    // cout << "\nNo p2:\n";
	    // imprime_no(segtree[2*node+2]);
	    // cout << "\nJoin:\n";
	    // imprime_no (join(segtree[2*node+1], segtree[2*node+2]));

        segtree[node] = join (segtree[2*node+1], segtree[2*node+2]);
    }
}

no make_node (int size){
	no aux;
	aux.size = size;
	aux.size_l = 0;
	aux.size_r = 0;
	aux.max_size = 0;
	aux.sum = 0;
	aux.sum_l = 0;
	aux.sum_r = 0;
	aux.max_sum = 0;
	return aux;
}

no query (int node, int l, int r, int i, int j){

    no p1, p2;

    //size overflow;
    if (l > r || l > j || r < i)
        return make_node (-1);

    //Intervalo incluido
    if (l >= i && r <= j)
        return segtree[node];

    //
    p1 = query (2*node+1, l, (l+r)/2, i, j); 
    p2 = query (2*node+2, (l+r)/2+1, r, i, j);

    if (p1.size == -1)
    	return p2;
    if (p2.size == -1)
    	return p1;
    // Condição: pai = max (fllho1, filho2);

    // cout << "\n\nQuery de nos:\n\n";
    // cout << "No p1:\n";
    // imprime_no (p1);
    // cout << "\nNo p2:\n";
    // imprime_no(p2);
    // cout << "\nJoin:\n";
    // imprime_no (join(p1, p2));
	return join (p1, p2);
}

void imprime (int N){
	for (int i=0; i<pow(2, log2(N)+1)-1; i++){
		cout << '[' << i << '-' << segtree[i].sum << ']' << ' ';
	}
	cout << endl;
}

int main (){

	ios::sync_with_stdio(false);
	
	int T, N, Q;
	int px, py;

	cin >> T;

	while (T--){
		cin >> N;

		for (int i=0; i<N; i++){
			cin >> vetor[i];
		}

		inicializa (0, 0, N-1);

		// imprime (N);

		cin >> Q;

		for (int i=0; i<Q; i++){
			cin >> px >> py;
			no resp = query (0, 0, N-1, px-1, py-1);
			cout << resp.max_sum << ' ' << resp.max_size << endl;
		}
	}

	

	return 0;
}
