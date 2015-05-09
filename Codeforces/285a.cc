#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int solver (int p, int t){
  return max (3*p/10, p - (p/250)*t);
} 

int main (){
  
  int a, b, c, d;

  cin >> a >> b >> c >> d;

  int x = solver (a, c);
  int y = solver (b, d);
  
  if (x == y)
    cout << "Tie\n";
  else if (x > y)
    cout << "Misha\n";
  else
    cout << "Vasya\n";
  return 0;
}
