/*
Problema - Comercio de camelos
http://br.spoj.com/problems/COMCAMEL/
Guilherme Leobas
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

string convertInt(int number){
	stringstream ss;
	ss << number;

	return ss.str();
}

void imprime (vector<long long int> v){
	for (int cont=0; cont<v.size(); cont++){
		cout << v[cont] << ' ';
	}
	cout << endl;
}

void pre_processa (string s, vector<long long int> &v){

	int num;
	int inicio;

	for (int cont=0; cont<s.size(); cont++){

		inicio = cont;

		num = 0;

		while (s[cont] != '*' && s[cont] != '+' && cont < s.size()){
			num = num*10 + (int)s[cont]-48;
			cont++;
		}

		v.push_back (num);
		if (s[cont] == '*'){
			v.push_back (-1);
		}
		
		if (s[cont] == '+'){
			v.push_back (-2);
		}

	}

	// imprime(v);
}

long long int minimo (vector<long long int> v){

	long long int resposta = 0;
	long long int mult = 1;

	vector<long long int>::iterator it;


	while (true){

		it = find(v.begin(), v.end(), -1);

		if (it == v.end()) break;

		it++;
		mult *= *it;
		it--; it--;
		mult *= *it;

		for (int i=0; i<3; i++){
			v.erase (it);
		}

		v.insert (it, mult);

		mult = 1;
	}

	for (int cont=0; cont<v.size(); cont++){
		if (v[cont] > 0){
			resposta += v[cont];
		}
	}

	// imprime (v);

	return resposta;

}

long long int maximo (vector<long long int> v){

	long long int resposta = 1;
	long long int soma = 0;

	vector<long long int>::iterator it;


	while (true){

		it = find(v.begin(), v.end(), -2);

		if (it == v.end()) break;

		it++;
		soma += *it;
		it--; it--;
		soma += *it;

		for (int i=0; i<3; i++){
			v.erase (it);
		}

		v.insert (it, soma);

		soma = 0;
	}

	for (int cont=0; cont<v.size(); cont++){
		if (v[cont] > 0){
			resposta *= v[cont];
		}
	}

	// imprime (v);

	return resposta;
}


int main(){

	string s;
	int n;
	int aux;
	vector<long long int> v;

	cin >> n;

	for (int i=0; i<n; i++){

		v.clear();

		cin >> s;
		pre_processa (s, v);

		cout << "The maximum and minimum are " << maximo (v) << " and " << minimo (v) << '.' << endl;
	}

	return 0;
}
