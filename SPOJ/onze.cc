// http://br.spoj.com/problems/ONZE/

#include <iostream>
#include <string>

using namespace std;

bool solver (string s){

	int par = 0, impar = 0;

	for (int i=0; i<s.size(); i=i+2){
		impar += (int) (s[i]-'0');
	}

	for (int i=1; i<s.size(); i=i+2){
		par += (int)(s[i]-'0');
	}

	if ((impar-par)%11 == 0)
		return true;

	return false;
}

int main (){

	string n;

	while (true){
		cin >> n;
		if (n == "0") break;

		if (solver (n))
			cout << n << " is a multiple of 11.\n";
		else
			cout << n << " is not a multiple of 11.\n";
	}

	return 0;
}