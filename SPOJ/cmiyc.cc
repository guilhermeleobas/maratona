#include <iostream>

using namespace std;

int main(){

	int t;

	cin >> t;

	for (int i=0; i<t; i++){
		long long n;
		cin >> n;

		if (n % 3 != 0)
			cout << 0 << endl;
		else
			cout << n/3 << endl;
	}

	return 0;
}
