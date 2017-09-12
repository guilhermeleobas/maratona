#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int main (){
  
  int n, k;
  cin >> n >> k;
  
  if (n*n < k){
    cout << "-1\n";
    return 0;
  }
  
  int v[110][110];
  
  for (int i=0; i<n; i++){
    if (k){
      v[i][i] = 1; k--;
    }
    else {
      break;
    }
    for (int j=0; j<n; j++){
      if (!v[i][j] and k >= 2){
        v[i][j] = v[j][i] = 1;
        k -= 2;
      }
    }
  }
  
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      cout << v[i][j] << ' ';
    }
    cout << endl;
  }
  
  return 0;
}
