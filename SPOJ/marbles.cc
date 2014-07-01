#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <fstream>
#include <functional>

using namespace std;

#define PI acos(-1)
#define cnt PI/180
typedef vector<vector<pair<int, int> > > graph;


// ax + by = t;
// ax = t mod b
long long int solucao (long long int t, long long int a, long long int b){

	for (long long int i = 0; i <= b; i++){
		if ((a*i)%b == t) return i;
	}
}

//Recebe dois inteiros {a, b} e retorna o mdc(a, b);
long long int mdc (long long int numerador, long long int denominador){
	
	long long int resto=-1;
	long long int quociente=-1;
	
	while (resto != 0){
		//Quociente;
		quociente = numerador/denominador;
		
		//Resto;
		resto = numerador%denominador;
		
		//Reatribuição;
		numerador = denominador;
		
		//Garante que a atribuição do resto não será zero;
		if (resto != 0) {
			denominador = resto;
		}
	}
	
	return denominador;
}




int main (){
	
	long long int t, n1, c1, n2, c2;
	long long int custo_a1, custo_a2, custo_b1, custo_b2;
	long long int total1, total2;


	while (true){
		cin >> t;

		if (t == 0) break;

		cin >> c1 >> n1 >> c2 >> n2;

		if (t%mdc(n1, n2) != 0 || (t < n1 && t < n2)){
			cout << "failed\n";
		}
		else {
			custo_a1 = solucao (t%n2, n1, n2);
			custo_a2 = (t-n1*custo_a1)/n2;

			custo_b2 = solucao (t%n1, n2, n1);
			custo_b1 = (t-n2*custo_b2)/n1;

			// cout << custo_a1 << ' ' << custo_a2 << endl << custo_b1 << ' ' << custo_b2 << endl;


			total1 = custo_a1*c1 + custo_a2*c2;
			total2 = custo_b1*c1 + custo_b2*c2;

			// cout << total1 << ' ' << total2 << endl;
			if (custo_a1 < 0 || custo_a2 < 0 || custo_b1 < 0 || custo_b2 < 0){
				cout << "failed\n";
			}
			else{
				if (total1 <= total2){
					cout << custo_a1 << ' ' << custo_a2 << endl;
				}
				else {
					cout << custo_b1 << ' ' << custo_b2 << endl;
				}
			}

		}

	}
	

	return 0;
}