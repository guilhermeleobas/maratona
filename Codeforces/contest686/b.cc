#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_sorted (vector<int> &v){
  int i = 0;
  for (int j=1; j<v.size(); j++){
    if (v[i] > v[j])
      return false;
    i = j;
  }
  return true;
}

void sort_me(vector<int> &v){
  
  
  while (not is_sorted(v)){
    
    int i = 0;
    for (int j=i+1; j<v.size(); j++){
      if (v[i] > v[j]){
        cout << i+1 << ' ' << j+1 << endl;
        swap (v[i], v[j]);
      }
      i += 1;
    }
  }

}

int main (){
  int n;
  cin >> n;
  
  vector<int> v(n);
  
  for (int i=0; i<n; i++){
    cin >> v[i];
  }
  
  sort_me (v);
  
  return 0;
}
