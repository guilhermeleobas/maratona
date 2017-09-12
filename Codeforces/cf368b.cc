#include <iostream>
#include <cmath>
using namespace std;

#define sz 100000 + 100

int v[sz];
int k[sz];
int found[sz];

int main (){
  
  int n, m;
  std::cin >> n >> m;
  
  for (int i=0; i<n; i++) std::cin >> v[i];
  
  found[v[n-1]] = 1;
  k[n-1] = 1;
  for (int i=n-2; i>=0; i--){
    int num = v[i];
    if (! found[num]){
      // cout << "setting found[" << num << "]\n";
      found[num] = 1;
      k[i] = k[i+1] + 1;
    }
    else {
      k[i] = k[i+1];
    }
  }
  
  for (int i=0; i<m; i++){
    int num;
    std::cin >> num;
    std::cout << k[num-1] << '\n';
  }
  
  return 0;
}
