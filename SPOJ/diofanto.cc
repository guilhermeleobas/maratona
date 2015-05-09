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
#define C 1300031
typedef vector<vector<pair<int, int> > > graph;

//A função irá retornar um inteiro P = (a^e)%n;
long long int modulo (long long int a, long long int e, long long int n){
	long long int A;
	long long int E;
	long long int P;

	//ETAPA 1: Atribuição de valores;
	A = a;
	E = e;
	P = 1;

	//ETAPA 2: Enquanto E for diferente de 0;
	while (E != 0){
	
        //ETAPA 3: Verifica se E é impar;
        if (E%2 != 0){
			P = (A*P)%n;
			E = (E-1)/2;
		}
		//ETAPA 4: Verifica se E é par;
		else {
			E = E/2;
		}

		//ETAPA 5: Incremento do A;
		A = (A*A)%n;

    }
    
	return P;
}

long long int fat (long long int x){
	
	long long int resp = 1;

	for (int cont=1; cont<=x; cont++){
		resp *= cont;
	}

	return resp;
}

long long int fat2 (int x, int lim){

	long long int resp = 1;

	for (int cont=x; cont>lim; cont--){
		resp*=cont;
	}

	return resp;
}

// ax + by = 1
// ax = 1 mod b
// Basta substituir t por 1;
long long int inv (long long int t, long long int a, long long int b){

	for (long long int i = 1; i <= b; i++){
		if ((a*i)%b == t) return i;
	}
}

int main (){
	
	int num_testes;
	int n, c;
	ios::sync_with_stdio(false);
	long long int inv[1000010];

	inv[0] = 1;

	for (int cont=1; cont<1000010; cont++){
		inv[cont] = (inv[cont-1]*modulo(cont, C-2, C))%C;
	}

	cin >> num_testes;

	for (int cont=0; cont<num_testes; cont++){
		cin >> n >> c;

		long long int resp = 1;

		resp = inv[n-1];
		// cout << resp << endl;

		for (int i=(n+c-1); i>c; i--){
			resp = (resp*i)%C;
		}

		cout << resp << endl;
		
	}

	return 0;
}
