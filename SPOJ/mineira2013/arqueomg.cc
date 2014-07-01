#include <iostream>

using namespace std;

int main(){
	
	int n;

	cin >> n;

	while (n--){
		int a, b;

		cin >> a >> b;

		int ans = b - a;

		if (a < 0 && b > 0)
			ans--;

		cout << ans << endl;
	}

	return 0;
}
