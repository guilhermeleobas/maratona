#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void process (vector<vector<int> > &v, int N){

	int x = 0;

	// cout << x << ' ' << N << endl;

	while (x < N-x){

		for (int i=x; i<N-x; i++){
			for (int j=x; j<N-x; j++){
				// cout << "Opa\n";
				v[i][j] += 1;
			}
		}
		x++;
	}
}

void imprime (vector<vector<int> > &v, int N){
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			printf ("%3d", v[i][j]);
			if (j < N-1)
				printf (" ");
		}
		printf ("\n");
	}
}

int main (){

	vector<vector<int> > v (110, vector<int> (110, 0));
	int N;

	while (true){
		cin >> N;

		v.clear();
		v.resize (N, vector<int> (N, 0));

		if (!N)
			break;

		process (v, N);
		imprime (v, N);
		cout << endl;
	}


	return 0;
}