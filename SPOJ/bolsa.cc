/*
Problema - Bolsa de valores
http://br.spoj.com/problems/BOLSA/
Guilherme Leobas
*/

#include <iostream>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;


int main (){
	
	ios::sync_with_stdio(false);

	priority_queue<double, vector<double>, less<double> > compra;
	priority_queue<double, vector<double>, greater<double> > venda;
	double resp, dig;
	char c;
	int n;

	while (true){
		cin >> n;

		if (n == 0) break;

		resp = 0;
		
		while (!compra.empty()){
			compra.pop();
		}

		while (!venda.empty()){
			venda.pop();
		}

		for (int cont=0; cont<n; cont++){
			cin >> c >> dig;

			if (c == 'C'){
				// cout << "Deu push em compra: " << dig << endl;
				compra.push (dig);
			}
			else {
				// cout << "Deu push em venda: " << dig << endl;
				venda.push (dig);
			}

			if (!compra.empty() && !venda.empty()){
				if (compra.top() >= venda.top()){
					resp += compra.top() - venda.top();
					compra.pop();
					venda.pop();
				}
				else {
					compra.top();
				}

			}
		}
		cout << setprecision(2) << fixed << resp << endl;
	}

	return 0;

}



