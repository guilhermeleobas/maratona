#include <iostream>
#include <cmath>

using namespace std;

int solver (int l, int a, int c, int e){
  return l*l - a*a - c*c - e*e;
}

int main (){
  
  int a, b, c, d, e, f;
  
  cin >> a >> b >> c >> d >> e >> f;
  
  // a, c, e
  // b, d, f
  
  cout << solver (a+b+c, a, c, e) << endl; 
  
  
  return 0;
}
