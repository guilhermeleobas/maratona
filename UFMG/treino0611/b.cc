#include <iostream>
#include <cmath>

using namespace std;

int min (int a, int b, int c){
  if (a <= b and a <= c)
    return a;
  if (b <= c and b <= a)
    return b;
  if (c <= a and c <= b)
    return c;
}

int main (){
  
  int n;
  cin >> n;
  
  while (n--){
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c == 180 and min (a, b, c) > 0){
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
