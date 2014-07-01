// http://www.urionlinejudge.com.br/judge/pt/problems/view/1114

#include <iostream>

using namespace std;

int main (){

	int n;

	while (true){
		cin >> n;

		if (n == 2002)
			cout << "Acesso Permitido\n";
		else 
			cout << "Senha Invalida\n";

		if (n == 2002)
			break;
	}
}