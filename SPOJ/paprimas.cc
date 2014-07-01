// http://br.spoj.com/problems/PAPRIMAS/

#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int conv (string s){
	int ans = 0;
	for (int i=0; i<s.size(); i++){
		//cout << ans << ' ' << s[i] << endl;
		if (s[i] >= 'a' && s[i] <= 'z')
			ans += s[i] - 'a' + 1;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			ans += s[i] - 'A' + 27;
	}


	return ans;
}

bool isprime (int n){
	
	for (int i=2; i<=sqrt(n); i++){
		if (n%i == 0) return false;
	}

	return true;
}

int main (){
	
	string s;

	while (true){
		cin >> s;

		if (not cin) break;

		int n = conv (s);

		if (isprime (n))
			cout << "It is a prime word." << endl;
		else
			cout << "It is not a prime word." << endl;

	}

	return 0;
}
