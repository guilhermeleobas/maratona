#include <iostream>

using namespace std;

int main (){
	
	int N, k;
	int num;
	int vetor[55];

	while (true){
		cin >> N;

		if (!N)
			break;

		for (int i=0; i<N; i++){
			cin >> vetor[i];
		}
		cin >> k;

		while (vetor[k-1] != k){
			k = vetor[k-1];
		}

		cout << vetor[k-1] << endl;
	}

	return 0;
}
