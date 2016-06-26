#include <iostream>
#include <cmath>

using namespace std;

int main (){
  
  long long n, k;
  cin >> n >> k;
  
  long long a = ceil(n/k);
  long long x = a*k;
  
  if (x <= n){
    cout << (a+1)*k << endl;
  }
  else{
    cout << x << endl;
  }
  
  return 0;
}
