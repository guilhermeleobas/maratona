#include <iostream>

using namespace std;

int gcd (int n, int d){
	return (d != 0) ? gcd (d, n%d) : n;
}


int main (){

	int n1, n2, d1, d2;
	char op1, op2, op3;
	int num, de;
	int n;

	cin >> n;

	while (n--){
		cin >> n1 >> op1 >> d1 >> op2 >> n2 >> op3 >> d2;
	
		if (op2 == '+'){
			num = (n1*d2 + n2*d1);
			de = d1*d2;
		}
		else if (op2 == '-'){
			num = (n1*d2 - n2*d1);
			de = d1*d2;
		}
		else if (op2 == '*'){
			num = (n1*n2);
			de = d1*d2;
		}
		else{
			num = n1*d2;
			de = n2*d1;
		}
		
		bool sign = false;

		if ((de < 0 && num > 0) || (de > 0 && num < 0)){
			sign = true;
			de < 0 ? de=de*-1 : de=de;
			num < 0 ? num=num*-1 : num=num;
		}

	
		if (gcd (num, de) == 1){
			cout << num << '/' << de << " = " << num << '/' << de << endl;
		}	
		else {
			int x = gcd (num, de);
			if (sign){
				cout << num*-1 << '/' << de << " = " << -1*(num/x) << '/' << de/x << endl;
			}
			else {
				cout << num << '/' << de << " = " << num/x << '/' << de/x << endl;
			}
		}

	}

	return 0;
}
