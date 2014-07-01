#include <iostream>

using namespace std;

int gcd (int n, int m){
	return m != 0 ? gcd (m, n%m) : n;
}

int main (){
	
	int N;
	int f1, f2;

	cin >> N;

	while (N--){
		cin >> f1 >> f2;
		cout << gcd (f1, f2) << endl;
	}

	return 0;
}
