#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main (){
  
  int n;
  cin >> n;
  
  while (n--){
    int t;
    cin >> t;
    vector<int> v (t);
    
    for (int i=0; i<t; i++){
      string s;
      cin >> s;
      if (s == "LEFT")
        v[i] = -1;
      else if (s == "RIGHT")
        v[i] = -2;
      else {
        cin >> s;
        cin >> v[i];
        v[i] -= 1;
      }
    }
    
    int ans = 0;
    
    for (int i=0; i<t; i++){
      int op = v[i];
      while (op >= 0)
        op = v[op];
      
      // cout << "op: " << op << endl;
      
      if (op == -1)
        ans -= 1;
      else
        ans += 1;
    }
    cout << ans << endl;
  }
  return 0;
}
