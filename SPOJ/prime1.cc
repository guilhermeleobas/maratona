#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <bitset>
#include <cmath>

using namespace std;

#define ll long long

ll _sieve_size;
bitset<10000010> bs;
vector<int> primes;

void segmented_sieve (int m, int n){
	bitset<100000> segmented;
	vector<ll> primesll;
	segmented.set(); // set all bits to 1;
	
	for (int i=0; i<primes.size(); i++){

		int prime = primes[i]*floor(m/primes[i]);
		if (prime < m) prime += primes[i];
	
		if (primes[i] >= n) break;
		if (primes[i] == prime) continue;

		for (int j = prime; j <= n; j += primes[i]) segmented[j-m] = 0;
	
	}

	for (int i=0; i<=n-m; i++){
		if (segmented[i])
			cout << m+i << endl;
			//primesll.push_back ((long long)m+i);
	}

	cout << endl;

}

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

void solver (int m, int n){
	vector<int>::iterator low, upper;

	low = lower_bound (primes.begin(), primes.end(), m);
	upper = upper_bound (primes.begin(), primes.end(), n);

	for (vector<int>::iterator it = low; it < upper; it++)
		cout << *it << endl;
	cout << endl;

}

int main(){

	sieve (10000010);

	int t, n, m;

	cin >> t;
	
	while (t--){
		cin >> m >> n;

		if (n < 10000000)
			solver (m, n);
		else
			segmented_sieve (m, n);
	}
	//print ();
	//cout << primes.size() << endl;
	
	return 0;
}
