/*
Problema - Parque Jurassico
http://br.spoj.com/problems/PARQUE/
Guilherme Leobas
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
#include <functional>
#include <map>
#include <utility>
#include <deque>
#include <iomanip>

using namespace std;

int vetor[110][110];

void lcs (string &a, string &b){

	int n = a.size();
	int m = b.size();

	for (int i=0; i<=n; i++){
		for (int j=0; j<=m; j++){

			if (i == 0 || j == 0){
				vetor[i][j] = 0;
			}
			else if (a[i-1] == b[j-1]){
				vetor[i][j] = 1 + vetor[i-1][j-1];
			}
			else{
				vetor[i][j] = max (vetor[i-1][j], vetor[i][j-1]);
			}
		}
	}

}


stack<char> sequence (string &a, string &b){
	stack<char> s;

	int i = a.size();
	int j = b.size();

	while (i != 0 && j != 0){

		// cout << a[i-1] << ' ' << b[j-1] << ' ' << i << ' ' << j << endl;

		if (a[i-1] == b[j-1]){
			s.push (a[i-1]);
			i--;
			j--;
		}
		else{
			// Mismach;
			if (vetor[i][j] == vetor[i-1][j]){
				s.push(a[i-1]);
				i = i-1;
			}
			else {
				s.push (b[j-1]);
				j = j-1;
			}
		}
	}

	while (i > 0){
		s.push (a[i-1]);
		i--;
	}

	while (j > 0){
		s.push (b[j-1]);
		j--;
	}

	return s;
}

void imprime (int n, int m){

	for (int i=0; i<= n; i++){
		for (int j=0; j<= m; j++){
			cout << vetor[i][j] << ' ';
		}
		cout << endl;
	}	
}

int main (){

	ios::sync_with_stdio(false);
	string a, b;
	stack<char> s;
	int test = 0;

	while (true){
		cin >> a >> b;

		if (a == "#") break;

		lcs (a, b);
		// imprime (a.size(), b.size());
		s = sequence (a, b);

		cout << "Teste " << ++test << endl;

		while (!s.empty()){
			cout << s.top();
			s.pop();
		}
		cout << endl << endl;
	}


  return 0;
}