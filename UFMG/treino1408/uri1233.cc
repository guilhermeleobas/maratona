#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

#define ll long long

ll _sieve_size;
bitset<55000> bs;
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

int divide (long long &n, int k){
  int aux = 0;
  while (n%k == 0 and n != 1){
    aux++;
    n /= k;
  }
  
  return aux;
}

long long pow (long long number, long long exp){
  long long ans = 1;
  for (int i=0; i<exp; i++)
    ans *= number;
  return ans;
}


long long phi (long long n){
  vector<int> v (sqrt(n) + 10);
  bool valid = false;
  for (int i=2; i<primes.size(); i++){
    if (n <= 1)
      break;
    v[i] = divide (n, i);
    if (v[i]){
      valid = true;
      cout << "dividido por " << i << " v[i] " << v[i] << " n = " << n << endl;
    }  
  }
  
  if (not valid){
    return (n-1);
  }
  
  long long ans = 1;
  
  for (int i=1; i<v.size(); i++){
    if (v[i]){
      ans *= (i-1)*pow(i, v[i]-1);
    }
  }
  
  return ans;
}

int main (){
  
  sieve (55000);
  while (true){
    long long n;
    cin >> n;
    
    if (not cin) break;
    
    cout << "recebeu " << n << " saida " << phi (n)/2 << endl;
  }
  return 0;
}
