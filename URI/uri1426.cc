#include <iostream>

using namespace std;

void reinicia (int m[10][10]){
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			m[i][j] = -1;
		}
	}
}

void imprime (int m[10][10]){
	for (int i=0; i<=8; i++){
		for (int j=0; j<=i; j++){
			cout << m[i][j];
			if (j < i)
				cout << ' ';
		}
		cout << endl;
	}
}

void solver (int m[10][10]){
	for (int i=8; i>=0; i--){
		for (int j=0; j<9; j++){
			if (m[i][j] == -1){
				if (i == 8)
					m[i][j] = (m[i-2][j-1] - m[i][j-1] - m[i][j+1])/2;
				else
					m[i][j] = m[i+1][j] + m[i+1][j+1];
			}
		}
	}
}

int main (){

	int m[10][10];
	int num, t;

	cin >> t;

	while (t--){

		reinicia (m);

		for (int i=0; i<5; i++){
			for (int j=0; j<=i; j++){
				cin >> num;

				// cout << t << ' ' << i << ' ' << j << endl;

				m[2*i][2*j] = num;
			}
		}
		solver (m);
		imprime (m);
	}


	return 0;
}