#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define mod 1000000

int main(){

	int n, k;
	int dp[110][110];
	

	for (int j=0; j<=100; j++){
		dp[0][j] = 0;
		dp[1][j] = j;
	}

	for (int i=0; i<=100; i++){
		for (int j=1;j<=100; j++){
			if (i == 1)
				dp[i][j] = j;
			else if (i == 0 || j == 1)
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i-1][j] + dp[i][j-1] + mod)%mod;
		}
	}

	for (int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	
	while (true){
		cin >> n >> k;

		if (not n and not k) break;

		cout << dp[n][k] << endl;
	}

	return 0;
}
