#include <iostream>
#include <vector>

using namespace std;

int solve (vector<int> v, int x){
  v.erase (v.begin() + x);
  int sum = 0;

  for (int i=0; i<v.size()-1; i++){
    sum = max (sum, v[i+1] - v[i]);
  }

  return sum;
}

int main (){
  
  int n;
  cin >> n;
  vector<int> v (n);

  for (int i=0; i<n; i++){
    cin >> v[i];
  }
  
  int max_sum = 0x3f3f3f3f;
  for (int i=1; i<n-1; i++){
    max_sum = min (max_sum, solve (v, i));
  }

  cout << max_sum << endl;
  return 0;
}
