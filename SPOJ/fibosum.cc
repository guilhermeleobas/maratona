// http://www.spoj.com/problems/FIBOSUM/

#include <iostream>

using namespace std;

#define mod 1000000007

long long solver (int n){
	long long resp[2][2] = {{1,0},{0,1}};
	long long x[2][2] = {{1,1},{1,0}};
	long long tmp[2][2] = {{0,0},{0,0}};
	
	while (n){
		if (n%2 != 0){
		
			// matrix multiplication;
			for (int i=0; i<2; i++){
				for (int j=0; j<2; j++){
					tmp[i][j] = 0;
					for (int k=0; k<2; k++){
						tmp[i][j] = (tmp[i][j] + resp[i][k]*x[k][j])%mod;
					}
				}
			}
			
			for (int i=0; i<2; i++)
				for (int j=0; j<2; j++)
					resp[i][j] = (tmp[i][j] + mod)%mod;
	
			n -= 1;
		}

		for (int i=0; i<2; i++){
			for (int j=0; j<2; j++){
				tmp[i][j] = 0;
				for (int k=0; k<2; k++){
					tmp[i][j] = (tmp[i][j] + x[i][k]*x[k][j])%mod;
				}
			}
		}

		for (int i=0; i<2; i++)
			for (int j=0; j<2; j++)
				x[i][j] = (tmp[i][j] + mod) % mod;


	
		n = n/2;
	}


	return resp[0][1];
}
	
int main(){
	
	long long t, n, m;

	cin >> t;

	while (t--){
		cin >> n >> m;

		cout << (solver (m+2) - solver (n+1)+mod)%mod << endl;
	}

	return 0;
}
