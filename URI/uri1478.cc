#include <iostream>
#include <cstdio>

using namespace std;

int v[110][110];

void imprime (int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf ("%3d", v[i][j]);
			if (j < n-1)
				cout << ' ';
		}
		cout << endl;
	}
}

int main (){

	for (int i=0; i<101; i++){
		for (int j=i; j<101; j++){
			if (i == j)
				v[i][j] = 1;
			else
				v[i][j] = v[i][j-1] + 1;
			v[j][i] = v[i][j];
		}
	}

	int n;

	while (true){
		cin >> n;

		if (n == 0)
			break;

		imprime (n);
		cout << endl;
	}

	return 0;
}