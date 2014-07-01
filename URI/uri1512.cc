/*
Problema - Azulejos
http://www.urionlinejudge.com.br/judge/pt/problems/view/1512
Guilherme Leobas
*/

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
#include <iomanip>

using namespace std;

#define PI acos(-1)
#define cnt PI/180
#define INF 99999999
typedef vector<vector<pair<int, int> > > graph;

// MDC
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

	ios::sync_with_stdio(false);
	
	int a, b, r;
	long long m, n;

	while (true){
		cin >> n >> a >> b;

		if (!n)
			break;

		r = 0;

		m = (a*b)/mdc (a, b);

		r += n/a;
		r += n/b;
		r -= n/m;

		cout << r << endl;
	}	

	

	return 0;
}