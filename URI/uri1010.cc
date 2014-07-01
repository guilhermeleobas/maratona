#include <iostream>
#include <iomanip>

using namespace std;

int main (){
	
	int cod;
	int q1, q2;
	float p1, p2;

	cin >> cod >> q1 >> p1;
	cin >> cod >> q2 >> p2;

	cout << fixed << setprecision(2) << "VALOR A PAGAR: R$ " << p1*q1 + p2*q2 << endl;

	return 0;
}
