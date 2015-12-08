#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long pow (int base, int c){
  long long ans = 1;
  for (int i=0; i<c; i++){
    ans *= base;
  }
  
  return ans;
}

long long calc (int base, vector<int> v){
  int c = v.size() - 1;
  long long ans = 0;
  for (int i=0; i<v.size(); i++){
    ans += pow (base, c)*v[i];
    c--;
  }
  
  
  return ans;
}

int main (){
  int n, bx, m, by;
  cin >> n >> bx;
  
  vector<int> x(n);
  for (int i=0; i<n; i++) cin >> x[i];
  long long rx = calc (bx, x);
  cin >> m >> by;
  vector<int> y(m);
  for (int i=0; i<m; i++) cin >> y[i];
  long long ry = calc (by, y);
  
  if (rx == ry){
    cout << "=" << endl;
  }
  else if (rx < ry){
    cout << "<" << endl;
  }
  else {
    cout << ">" << endl;
  }
  
}
