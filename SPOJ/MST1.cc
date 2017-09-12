#include <iostream>
#include <cmath>
#include <map>
#include <cstring>

using namespace std;

#define sz 20000000 + 100
int v[sz+ 100];

int main (){
  
  memset (v, 0x3f3f3f3f, sizeof(int)*sz + 10);
  
  v[1] = 0;
  for (int i=2; i<sz + 10; i++){
    if (i % 2 == 0)
      v[i] = min (v[i], v[i/2]+1);
    if (i % 3 == 0)
      v[i] = min (v[i], v[i/3]+1);
    v[i] = min (v[i], v[i-1]+1);
  }
  
  int t;
  cin >> t;
  
  int c = 1;
  
  while (t--){
    int n;
    cin >> n;
    cout << "Case " << c++ << ": " << v[n] << endl;
  }
  
  return 0;
}
