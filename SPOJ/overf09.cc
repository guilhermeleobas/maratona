#include <iostream>

using namespace std;

int main(){
	
	int overflow;
	int op1, op2;
	char q;

	cin >> overflow >> op1 >> q >> op2;

	if (q == '+')
		op1 += op2;
	else
		op1 *= op2;

	if (op1 > overflow)
		cout << "OVERFLOW\n";
	else
		cout << "OK\n";

	return 0;
}
