
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <bitset>

using namespace std;

#define ll long long

ll _sieve_size;
#define sz 1000001
long long dp[sz];
long long arr[sz];

void sieve (ll upperbound){
	
	_sieve_size = upperbound + 1;
  
  for (ll i = 2; i <= _sieve_size; i++)
    dp[i] = 1;

	for (ll i = 2; i <= _sieve_size; i++){
    ll j = 2;
    while ( i * j <= _sieve_size){
      dp[i*j] += i;
      j += 1;
    }
	}
  
  for (ll i = 2; i <= _sieve_size; i++)
    arr[i] = arr[i-1] + dp[i];
}


int main (){
  
  int t;
  cin >> t;
  
  sieve(sz);
  
  long long p = 0;
  arr[0] = arr[1] = 0;
  
  while (t--){
    long long n;
    cin >> n;
    cout << arr[n] << '\n';
  }
  
  return 0;
}
