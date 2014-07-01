#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
	
	int n;

	while (true){
		cin >> n;

		if (n == 0) break;

		string s;
		set<string> conj;

		for (int i=0; i<n; i++){
			cin >> s;
			sort (s.begin(), s.end());
			conj.insert (s);
		}
		
		cout << conj.size() << endl;
	}	

	return 0;
}
