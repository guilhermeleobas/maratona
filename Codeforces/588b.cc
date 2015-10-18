#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

int main (){

  long long n;
  cin >> n;
  
  long long ans = 1;
  
  for (int i=2; i<=sqrt(n) + 1; i++){
    if (n == 1) break;
    
    if (n % i == 0)
      ans *= i;
    
    while (n % i == 0){
      n /= i;
    }
  }
  
  if (n != 1)
    ans *= n;
  
  cout << ans << endl;
  
  return 0;
}
