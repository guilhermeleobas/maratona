#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int t;
	vector<string> v;
	string s;

	while (true){
		cin >> t;

		if (t == 0) break;

		v.clear();

		for (int i=0; i<t; i++){
			cin >> s;
			sort (s.begin(), s.end());
			v.push_back (s);
		}

		sort (v.begin(), v.end());

		int cnt = 1;

		for (int i=1; i<v.size(); i++)
			if (v[i] != v[i-1])
				cnt++;

		cout << cnt << endl;
			
	}

	return 0;
}
