#include <iostream>
#include <vector>

using namespace std;

int arr[1000001];

int main (){
	
	int k, l, m;

	cin >> k >> l >> m;

	arr[0] = 0;

	for (int i=1; i<=1000000; i++){
		if (i-k >= 0 && not arr[i-k]) arr[i] = 1;
		if (i-l >= 0 && not arr[i-l]) arr[i] = 1;
		if (i-1 >= 0 && not arr[i-1]) arr[i] = 1;
	}

	for (int i=0; i<m; i++){
		int t;
		cin >> t;

		if (arr[t]) cout << "A";
		else cout << "B";
	}
	cout << endl;

	

	return 0;
}
