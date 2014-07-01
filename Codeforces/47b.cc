#include <map>
#include <string>
#include <iostream>

using namespace std;

int main(){
	
	map<char, long long> m;
	string s;

	cin >> s;

	for (int i=0; i<s.size(); i++){
		m[s[i]]++;
	}

	long long ans = 0;
	for (int i=0; i<s.size(); i++)
		ans += m[s[i]];

	cout << ans << endl;

	return 0;
}
