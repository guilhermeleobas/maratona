/*
Problema - Botas perdidas
http://br.spoj.com/problems/BOTAS/
Guilherme Leobas
*/

#include <map>
#include <iostream>
#include <cstdio>

using namespace std;

typedef multimap<int, char> mp;

void imprime (mp &m){
	mp::iterator it;

	for (it = m.begin(); it!= m.end(); it++){
		cout << it->first << ' ' << it->second << endl;
	}
}

int main(){

	mp m;
	int tam;
	char pe;
	int n;
	int num;
	int contador;
	int esq, dir;
	mp::iterator it;

	while (scanf ("%d", &n) != EOF){
		m.clear();
		while (n-- > 0){
			cin >> tam;
			cin >> pe;
			m.insert (pair<int, char> (tam, pe));
		}
		
		//imprime (m);

		contador = 0;
		it = m.begin();
		while (it != m.end()){
			num = it->first;
			esq = 0;
			dir = 0;
			while (num == it->first){
				if (it->second == 'E'){
					esq++;
				}
				else {
					dir++;
				}
				it++;
			}
			if (esq > dir){
				contador += dir;
			}
			else {
				contador += esq;
			}
		}
		cout << contador << endl;
	}


	return 0;
}