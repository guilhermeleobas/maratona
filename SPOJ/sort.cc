// Problem set: http://www.urionlinejudge.com.br/judge/pt/problems/view/1252
// Guilherme Leobas;

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mod;

bool compare (int a, int b){

	int	mod_a = a%mod;
	int mod_b = b%mod;
	bool par_a, par_b;
	
	if (a%2 == 0)
		par_a = true;
	else
		par_a = false;

	if (b%2 == 0)
		par_b = true;
	else
		par_b = false;

	if (mod_a == mod_b){
		if (!par_a && !par_b){
			// dois impares;
			if (a < b) return false;
			else return true;
		}
		else if (!par_a && par_b){
			// impar - par;
			return true;
		}
		else if (par_a && !par_b){
			// par - impar;
			return false;
		}
		else {
			// Dois pares;
			if (a < b) return true;
			else return false;
		}
	}
	else {
		// Modulos diferentes;
		if (mod_a < mod_b) return true;
		else return false;
	}
}

void imprime (vector<int> &v){
	for (int i=0; i<v.size(); i++){
		cout << v[i] << endl;
	}
}

int main (){

	int n, m;
	vector<int> v;

	while (true){
		cin >> n >> m;

		if (n == 0 && m == 0) break;
		mod = m;
	
		v.resize (n, 0);
		for (int i=0; i<n; i++){
			cin >> v[i];
		}

		sort (v.begin(), v.end(), compare);
		cout << n << ' ' << m << endl;
		imprime (v);
	}
	cout << "0 0\n";

	return 0;
}
