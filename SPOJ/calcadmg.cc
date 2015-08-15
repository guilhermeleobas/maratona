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
	
	int testes;
	long long int x1, x2, y1, y2;
	int emedc;
	cin >> testes;

	long long int resp = 0;

	while (testes-- > 0){
		cin >> x1 >> y1 >> x2 >> y2;

		resp = 1;

		if (x1 != x2 && y1 != y2){
			resp += mdc (abs(x1-x2), abs(y1-y2));
		}
		else {
			resp += max(abs(x1-x2), abs(y1-y2));
		}

		cout << resp << endl;

	}
	

	

	return 0;
}