#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main (){
  
	while (true){
		int n;
		cin >> n;
		if (not cin) break;

		vector<int> v (n);
		
		int s = 0;
		for (int i=0; i<n; i++){
			cin >> v[i];
			s += v[i];
		}

		int diff = 0;
		int k = s/n;

		for (int i=0; i<n; i++)
			diff += abs(k-v[i]);
		
		if (s % n == 0)
			cout << (diff/2) + 1 << endl;
		else
			cout << "-1\n";
	}

  return 0;
}
