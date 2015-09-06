#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main (){
  
  //  1 - 1
  //  2 - 5
  //  3 - 11
  //  4 - 19
  
  vector<int> v (100 + 1);
  v[0] = 0;
  v[1] = 1;
  int x = 4;
  for (int i=2; i<=100; i++){
    v[i] = v[i-1] + (i*i);
    x += 2;
  }
  
  while (true){
    int n;
    cin >> n;
    if (n == 0) break;
    else cout << v[n] << endl;
    
  }
  
  return 0;
}
