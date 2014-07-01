/*
Problema - Jogo do Bicho
http://br.spoj.com/problems/BICHO/
Guilherme Leobas
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <iomanip>

using namespace std;

int max (int nn, int mm){
	if (nn > mm) return nn;

	return mm;
}

int min (int nn, int mm){
	if (nn > mm) return mm;

	return nn;
}

int equals (int n, int m){

	int nn, mm;

	nn = n%100;
	mm = m%100;

	if (nn == mm){
		return 2;
	}
		else if (max(nn, mm)-min(nn, mm) <= 3 && min(nn, mm) != 0){
		return 1;
	}
	else if (max(nn, mm) >= 97 && min(nn, mm) == 00){
		return 1;
	}


	return 0;
}

int main (){

	double v;
	int n, m;
	int constante;

	while (true){
		cin >> v >> n >> m;

		if (v == 0 && n == 0 && m == 0) break;

		constante = equals (n, m);

		if (n%10000 == m%10000){
			cout << setprecision(2) << fixed << v*3000 << endl;
		}
		else if (n%1000 == m%1000){
			cout << setprecision(2) << fixed << v*500 << endl;
		}
		else if (constante == 2){
			cout << setprecision(2) << fixed << v*50 << endl;
		}
		else if (constante == 1){
			cout << setprecision(2) << fixed << v*16 << endl;
		}
		else if (constante == 0){
			cout << "0.00" << endl;
		}
	}


	return 0;
}
