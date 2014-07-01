//Link: http://www.spoj.com/problems/FASHION/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

typedef vector<int> dk;

int main (){

	dk men;
	dk woman;
	int n;
	int t;
	int rate;
	int soma;

	cin >> t;

	while (t-- > 0){
		
		cin >> n;

		soma = 0;
		men.clear();
		woman.clear();

		for (int cont=0; cont<2; cont++){
			for (int aux=0; aux<n; aux++){
				cin >> rate;
				if (cont == 0){
					men.push_back (rate);
				}
				else {
					woman.push_back (rate);
				}
			}
		}

		sort (men.begin(), men.end());
		sort (woman.begin(), woman.end());


		for (int cont=0; cont<n; cont++){
			soma += men[cont]*woman[cont];
		}

		cout << soma << endl;
	}


	return 0;
}