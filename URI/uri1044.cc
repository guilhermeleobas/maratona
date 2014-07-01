// http://www.urionlinejudge.com.br/judge/pt/problems/view/1044

#include <iostream>

using namespace std;

int main (){

	int a, b;

	cin >> a >> b;

	if (a < b)
		swap (a, b);

	if (a%b == 0)
		cout << "Sao Multiplos\n";
	else 
		cout << "Nao sao Multiplos\n";

	return 0;
}