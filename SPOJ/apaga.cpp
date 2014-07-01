//http://br.spoj.com/problems/APAGA/

#include <iostream>
#include <deque>

using namespace std;

void imprime (deque<char> r){

	deque<char>::iterator it;
	for (it = r.begin(); it != r.end(); it++){
			cout << *it;
	}
	cout << endl;
}

int main (){

	deque<char> r;
	int n, d, limite;
	char num[100002];

	while (true){

		cin >> n >> d;
		if (n == 0 && d == 0) break;

		limite = n - d;

		cin >> num;

		for (int cont=0; cont<n; cont++){

			while (!r.empty() && num[cont] > r.back() && d > 0){
				//imprime (r);
				r.pop_back();
				d--;
			}

			if (r.size() < limite){
				r.push_back (num[cont]);
			}
		}

		imprime (r);

		r.clear();
	}

	return 0;
}