#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
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

bool is_prime(int number){
  return binary_search (begin(primes), end(primes), number);
}


int main (){
  
  sieve(10000000);
  int n;
  cin >> n;
  vector<int> v(n);
  int one = 0;
  
  for (int i=0; i<n; i++){
    cin >> v[i];
    if (v[i] == 1)
      one++;
  }
  
  vector<int> p;
  
  for (int i=0; i<v.size(); i++){
    for (int j=i+1; j<v.size(); j++){
      if (is_prime(v[i] + v[j]) ){
        p.push_back(v[i]);
        p.push_back(v[j]);
        break;
      }
    }
    if (p.size() > 0)
      break;
  }
  
  vector<int> q;
  
  for (int i=0; i<v.size(); i++){
    if (v[i] == 1)
      continue;
    if (is_prime(v[i] + 1)){
      q.push_back(v[i]);
      break;
    }
  }
  
  if (one == 0 and p.size() == 0 and q.size() == 0){
    cout << "1\n";
    cout << v[0] << endl;
  }
  else if (p.size() > q.size() + one){
    cout << p.size() << endl;
    for (auto i: p){
      cout << i << ' ';
    }
    cout << endl;
  }
  else {
    cout << q.size() + one << endl;
    for (int i=0; i<one; i++){
      cout << "1 ";
    }
    if (not q.empty())
      cout << q[0] << endl;
  }
   
  
  
  return 0;
}
