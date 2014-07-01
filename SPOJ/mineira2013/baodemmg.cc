#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		int sum = 0;

		for (int i=0; i<n; i++){
			int aux; 
			cin >> aux;
			sum += aux;
		}


		if (sum <= n)
			cout << "nao precisa\n";
		else
			cout << "precisa\n";
	}

	return 0;
}
