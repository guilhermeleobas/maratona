#include <iostream>
#include <vector>

using namespace std;

int main (){

	int n;
	vector<int> v;
	int zero;
	int dif;
	int aux;

	while (true){
		cin >> n;
		if (n == 0) break;

		dif = 0;
		v.clear();

		for (int cont=0; cont<n; cont++){
			cin >> aux;
			if (aux != 0) {dif++; v.push_back (aux);}			
		}


		if (dif == 0){
			cout << "0\n";
		}
		else {
			cout << v[0];
			for (int cont=1; cont<v.size(); cont++){
				cout << ' ' << v[cont];
			}
			cout << endl;
		}


	}

	return 0;
}