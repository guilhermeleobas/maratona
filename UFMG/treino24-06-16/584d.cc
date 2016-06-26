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
bitset<10000010> bs;
vector<int> primes;

void sieve (ll upperbound){
	
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;

	for (ll i = 2; i <= _sieve_size; i++){
		if (!bs[i]) continue;

		for (ll j = i; j <= _sieve_size; j += i)
			bs[j] = 0;

		primes.push_back ((int)i);
	}
}

void print (){
	
	for (int i=0; i<primes.size(); i++)
		cout << primes[i] << ' ';
	cout << endl;
}

bool is_prime (int n){
  if (n % 2 == 0)
    return false;
  for (int i=3; i<=sqrt(n); i+=2){
    if (n % i == 0){
      return false;
    }
  }
  return true;
}

int main (){

  sieve(10000010);
  
  int n;
  cin >> n;
  
  if (is_prime(n)){
    cout << "1\n" << n << '\n';
  }
  else {
    int p = n-2;
    while (not is_prime(p))
      p--;
    
    for (int i=0; i<primes.size(); i++){
      if (p + primes[i] == n){
        cout << "2\n";
        cout << p << ' ' << primes[i] << endl;
        return 0;
      }
      for (int j=0; j<primes.size(); j++){
        if (primes[i] + primes[j] == n-p){
          cout << "3\n";
          cout << p << ' ' << primes[i] << ' ' << primes[j] << endl;
          return 0;
        }
      }
    }
    
  }
  
  return 0;
}
