#include <iostream>

using namespace std;

int main (){

	int a, b, c;

	while (true){
		cin >> a >> b >> c;

		if (!cin) break;

		int sum = a + b + c;

		if (sum == 0 || sum == 3)
			cout << "*\n";
		else if (sum == 1){
			if (a == 1)
				cout << "A\n";
			else if (b == 1)
				cout << "B\n";
			else
				cout << "C\n";
		}
		else {
			if (a == 0)
				cout << "A\n";
			else if (b == 0)
				cout << "B\n";
			else
				cout << "C\n";
		}
	}

	return 0;
}
