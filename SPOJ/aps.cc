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
#define sz 10000010
bitset<sz> bs;
long long dp[sz];
long long arr[sz];

/*
 * 2 - 2
 * 3 - 5
 * 4 - 7
 * 5 - 12
 * 6 - 14
 * 7 - 21
 * 8 - 23
 * 9 - 26
 * 
*/

void sieve (ll upperbound){
	
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;

	for (ll i = 2; i <= _sieve_size; i++){
		if (!bs[i]) continue;

    for (ll j = i; j <= _sieve_size; j += i){
      bs[j] = 0;
      if (dp[j] == 0)
        dp[j] = i;
    }

		// primes.push_back ((int)i);
	}
}


int main (){
  
  int t;
  cin >> t;
  
  sieve(sz);
  
  long long p = 0;
  arr[0] = arr[1] = 0;
  
  for (int i=2; i<sz; i++){
    long long a = p + dp[i];
    arr[i] = a;
    p = a;
  }
  
  // cout << "passou" << endl;
  
  while (t--){
    long long n;
    cin >> n;
    cout << arr[n] << '\n';
  }
  
  return 0;
}

