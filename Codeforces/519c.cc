#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main (){
  
  int n, m;

  cin >> n >> m;
  int sum = 0;

  while (true){
    if (n > m)
      swap (n, m);

    if (m >= 2 and n >= 1){
      sum += 1;
      m -= 2;
      n -= 1;
    }
    else
      break;
  }

  cout << sum << endl;

  return 0;
}
