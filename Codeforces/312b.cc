#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef struct interv {
  int left, right, sum;
  interv (){
    left = 0;
    right = 0;
    sum = 0;
  }
  interv (int l, int r, int s){
    left = l;
    right = r;
    sum = s;
  }
} interv;

int main (){
  
  int n;
  cin >> n;
  map<int, interv> m;
  
  for (int i=0; i<n; i++){
    int k;
    cin >> k;
    if (m.find (k) == m.end()){
      // nao existe;
      m[k] = interv (i, i, 1);
    }
    else {
      // atualiza
      m[k].right = i;
      m[k].sum += 1;
    }
  }
  
  int max_sum = -1;
  int l = 0, r = 0;
  for (map<int, interv>::iterator it = m.begin(); it != m.end(); it++){
    if (it->second.sum > max_sum){
      max_sum = it->second.sum;
      l = it->second.left;
      r = it->second.right;
    }
    else if (it->second.sum == max_sum){
      if (abs(it->second.left - it->second.right) < abs(l-r)){
        l = it->second.left;
        r = it->second.right;
      }
    }
  }
  
  cout << l+1 << ' ' << r+1 << endl;
  
  return 0;
}
