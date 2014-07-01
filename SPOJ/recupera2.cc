// http://br.spoj.com/problems/RECUPERA/

#include <iostream>

using namespace std;

int main(){

	int arr[101];
	int sum[101];
	int n, test = 0;
	bool check = false;

	while (true){
		cin >> n;

		if (!cin) break;

		for (int i=0; i<n; i++)
			cin >> arr[i];

		check = false;
	
		if (n == 1){
			check = true;
			cout << "Instancia " << ++test << "\n" << arr[0] << "\n\n";
		}

		for (int i=1; i<n; i++){
			if (arr[i-1] == arr[i]){
				cout << "Instancia " << ++test << "\n" << arr[i] << "\n\n";
				check = true;
				break;
			}
			else {
				arr[i] += arr[i-1];
			}
		}

		if (!check){
			cout << "Instancia " << ++test << "\nnao achei\n\n";
		}

	}

	return 0;
}
