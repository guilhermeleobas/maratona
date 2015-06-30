#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
	
	while (true){
		int n, g;
		cin >> n >> g;
		if (not cin) break;
		
		vector<int> v;
		int sum = 0;
		int equals = 0;
		for (int i=0; i<n; i++){
			int a, b;
			cin >> a >> b;

			if (a > b){
				sum+=3;
			}
			else if (a == b){
				equals++;
			}
			else {
				v.push_back (b-a);
			}
		}

		while (g > 0 and equals > 0){
			g--;
			equals--;
			sum+=3;
		}
		
		if (equals)
			sum += equals;
	
		sort (v.begin(), v.end());

		for (int i=0; i<v.size(); i++){
			if (g > v[i]){
				g -= v[i]+1;
				sum += 3;
			}
			else if (g == v[i]){
				g -= v[i];
				sum += 1;
			}
		}

		cout << sum << endl;
	}
	return 0;
}
