#include <iostream>
#include <vector>

using namespace std;

int main(){

	int n;

	while (true){
		cin >> n;

		if (n == -1) break;

		vector<int> v (n);
		int sum = 0;

		for (int i=0; i<n; i++){
			cin >> v[i];
			sum += v[i];
		}

		int t = sum/n;

		if (t*n != sum){
			cout << "-1\n";
			continue;
		}

		int ans = 0;

		for (int i=0; i<n; i++){
			if (v[i] > t){
				ans += v[i]-t;
			}
		}

		cout << ans << endl;


	}

	return 0;
}
