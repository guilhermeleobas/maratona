/*
Problema - Encontre o telefone
http://br.spoj.com/problems/ENCOTEL/
Guilherme Leobas
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>

using namespace std;

int main (){

	string word;

	while (true){

		word.clear();

		cin >> word;

		if (!cin) break;

		for (int cont=0; cont<word.size(); cont++){
			if ((word[cont] == 'A') || (word[cont] == 'B') || (word[cont] == 'C')){
				cout << '2';
			}
			else if ((word[cont] == 'D') || (word[cont] == 'E') || (word[cont] == 'F')){
				cout << '3';
			}
			else if ((word[cont] == 'G') || (word[cont] == 'H') || (word[cont] == 'I')){
				cout << '4';
			}
			else if ((word[cont] == 'J') || (word[cont] == 'K') || (word[cont] == 'L')){
				cout << '5';
			}
			else if ((word[cont] == 'M') || (word[cont] == 'N') || (word[cont] == 'O')){
				cout << '6';
			}
			else if ((word[cont] == 'P') || (word[cont] == 'Q') || (word[cont] == 'R') || (word[cont] == 'S')){
				cout << '7';
			}
			else if ((word[cont] == 'T') || (word[cont] == 'U') || (word[cont] == 'V')){
				cout << '8';
			}
			else if ((word[cont] == 'W') || (word[cont] == 'X') || (word[cont] == 'Y') || (word[cont] == 'Z')){
				cout << '9';
			}
			else {
				cout << word[cont];
			}
		}
		cout << endl;
	}
	



	return 0;
}

