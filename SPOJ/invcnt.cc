/*
Problema - Inversion Count - MergeSort
http://www.spoj.com/problems/INVCNT/
Guilherme Leobas
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

#define max 100000000

long long int soma = 0;

void imprime (vector<int> vetor){
	for (int cont=0; cont<vetor.size(); cont++){
		if (vetor[cont] != max){
			cout << vetor[cont] << ' ';
		}
	}
	cout << endl;
}

vector<int> concatena (vector<int> left, vector<int> right){

	int l, r, m;
	vector<int> result;

	m = max;

	l = r = 0;

	left.push_back (m);
	right.push_back (m);

	while (left[l] != max && right[r] != max){
		

		if (left[l] > right[r]){
			result.push_back (right[r]);
			r++;
			if (r+left.size() > l){
				soma += r + left.size() - result.size() - 1;
			}
		}
		else {
			result.push_back (left[l]);
			l++;
		}
	}

	while (left[l] != max){
		result.push_back (left[l]);
		l++;
	}

	while (right[r] != max){
		result.push_back (right[r]);
		r++;
	}

	return result;
}

vector<int> merge (vector<int> vetor){

	if (vetor.size() <= 1) return vetor;

	int meio = vetor.size()/2;

	vector<int> left (vetor.begin(), vetor.begin()+meio);
	vector<int> right (vetor.begin()+meio, vetor.end());

	left = merge (left);
	right = merge (right);

	vetor = concatena (left, right);

	return vetor;

}

int main(){

	vector<int> vetor;

	// ints;
	int t, n, aux;

	cin >> t;

	while (t-- > 0){
		cin >> n;

		soma = 0;
		vetor.clear();

		for (int cont=0; cont<n; cont++){
			cin >> aux;
			vetor.push_back (aux);
		}

		vetor = merge (vetor);
		printf ("%lld\n", soma);
	}


	return 0;
}

