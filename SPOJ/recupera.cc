// http://br.spoj.com/problems/RECUPERA/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
	int n;
	int arr[101];
	int sum[101];
	int test = 0;
	bool check = false;

	while (true){
		cin >> n;

		if (!cin) break;

		for (int i=0; i<n; i++)
			cin >> arr[i];

		for (int i=0; i<n; i++){
			int soma = 0;
			check = false;
			for (int j=0; j<i; j++){
				soma += arr[j];
			}
			if (soma == arr[i]){
				cout << "Instancia " << ++test << endl;
				cout << soma << endl << endl;
				check = true;
				break;
			}
		}

		if (!check)
			cout << "Instancia " << ++test << endl << "nao achei\n\n";
	}
	return 0;
}
