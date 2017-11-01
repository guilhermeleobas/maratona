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

void imprime (vector<int> &v){
	for (int i=0; i<v.size(); i++){
		cout << v[i] << ' ';
	}
	cout << endl;
}


int main(){

	ios::sync_with_stdio(false);

	vector<int> v;

	// ints;
	int t, n, aux;

	while (true){
		cin >> n;

		if (n == 0) break;

		soma = 0;
		v.clear();

		v.push_back (0);

		for (int cont=0; cont<n; cont++){
			cin >> aux;
			v.push_back (aux);
		}

		for (int i=1; i<=v.size()-1; i++){

			if (v[i] != i){
				swap (v[i], v[v[i]]);
				i = i-1;
				soma++;
			}

		}

		if (soma%2 == 0) cout << "Carlos\n";
		else cout << "Marcelo\n";

	}


	return 0;
}
