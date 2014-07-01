#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

#define MAX 100001

int v[MAX];
int row[MAX];

void print (int vetor[MAX], int n){
	for (int i=0; i<n; i++)
		cout << vetor[i] << ' ';
	cout << endl;
}

int calcmax (int vetor[MAX], int n){
	for (int j=n-2; j>=0; j--){
		vetor[j] = max (vetor[j+2]+vetor[j], vetor[j+1]);
	}
	
	return vetor[0];
}

int main (){
	
	while (true){
		int n, m;

		cin >> m >> n;

		v[m] = 0;
		v[m-1] = 0;
		v[m+1] = 0;

		row[n] = 0;
		row[n-1] = 0;
		row[n+1] = 0;

		if (not n && not m) break;
	
		for (int i=0; i<m; i++){
			for (int j=0; j<n; j++){
				cin >> row[j];
			}
			v[i] = calcmax (row, n);
			
		}
		
		int ans = calcmax (v, m);
		cout << ans << endl;
	}

	return 0;
}
