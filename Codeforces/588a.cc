#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main (){
  
  int n;
  int price = 0x3f3f3f3f;
  int ans = 0;
  cin >> n;
  for (int i=0; i<n; i++){
    int a, p;
    cin >> a >> p;
    price = min (price, p);
    ans += a * price;
  }
  
  cout << ans << endl;
  
  return 0;
}
