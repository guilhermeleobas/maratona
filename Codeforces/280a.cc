#include <iostream>

long long v[10000 + 100];

using namespace std;

int main (){

  int n;
  cin >> n;
  
  for (int i=1; i<100; i++){
    v[i] = v[i-1] + i;
  }

  for (int i=1; i<100; i++){
    if (n - v[i] > 0)
      n -= v[i];
    else if (n - v[i] == 0){
      cout << i << endl;
      break;
    }
    else {
      cout << i-1 << endl;
      break;
    }
  }

  return 0;
}
