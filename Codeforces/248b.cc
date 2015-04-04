#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
  
  int n;
  cin >> n;
  vector<long long> v (n+1), u(n+1);

  v[0] = 0;
  u[0] = 0;

  for (int i=1; i<=n; i++){
    cin >> v[i];
    u[i] = v[i];
  }

  sort (u.begin(), u.end());

  for (int i=2; i<=n; i++){
    u[i] += u[i-1];
    v[i] += v[i-1];
  }

  u.push_back (0);
  v.push_back (0);

  int t;
  cin >> t;

  while (t--){
    int type, l, r;
    cin >> type >> l >> r;

    if (type == 1){
      cout << v[r] - v[l-1] << endl;
    }
    else {  
      cout << u[r] - u[l-1] << endl;
    }
  }

  
}
