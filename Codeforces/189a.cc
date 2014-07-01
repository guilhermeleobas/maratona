// http://codeforces.com/problemset/problem/320/A

#include <iostream>
#include <string>

using namespace std;

bool solver (string s){
	int i = 0;
	while (i < s.size()){
		
		if (s[i] != '1') return false;

		if (i+1 < s.size() && s[i+1] == '4')
			i++;

		if (i+1 < s.size() && s[i+1] == '4')
			i++;

		i++;
	}

	return true;
}

int main (){
	
	string s;

	cin >> s;
	
	if (solver (s))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
