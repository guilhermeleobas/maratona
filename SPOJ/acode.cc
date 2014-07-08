#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	while (true){
		string s;
		cin >> s;

		if (s == "0") break;

		int dp[5001];
		fill (dp, dp+5001, 0);

		dp[s.size()] = 1;

		for (int i=s.size()-1; i >=0; i--){
			if (s[i] == '0') continue;
			dp[i] = dp[i+1];

			int t = (int)(s[i]-'0') * 10 + (int)(s[i+1]-'0');
			if (t >= 10 && t <= 26) dp[i] += dp[i+2];
		}
		
		cout << dp[0] << endl;
	}

	return 0;
}
