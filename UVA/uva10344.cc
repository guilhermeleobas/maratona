#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n[5];

bool bt (int sum, int i){
	if (i == 5)
		return sum == 23;	

	return (bt (sum*n[i], i+1) || bt (sum+n[i], i+1) || bt (sum-n[i], i+1));
}

int main(){

	while (true){
		for (int i=0; i<5; i++)
			cin >> n[i];
	
		if (not n[0] and not n[1] and not n[2] and not n[3] and not n[4]) break;
	
		sort (n, n+5);

		bool t = false;

		do {
			if (bt (n[0], 1)){
				t = true;
				break;
			}
		} while (next_permutation (n, n+5));
	
		if (t) cout << "Possible\n";
		else cout << "Impossible\n";
	}
	
	return 0;
}
