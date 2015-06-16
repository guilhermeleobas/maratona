#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long solver (vector<int> &v){
  long long sum = 0;
  int t[3];
  t[0] = 1;
  t[1] = 0;
  t[2] = 0;
  
  long long ans = 0;
  for (int i=0; i<v.size(); i++){
    sum += v[i];
    sum = sum % 3;
    ans += t[sum];
    t[sum]++;
  }

  return ans;
}

int main (){

  while (true){
    
    string s;
    cin >> s;
    if (not cin) break;
    vector<int> v;
    long long ans = 0;
    for (int i=0; i<s.size(); i++){
      if (s[i] >= '0' and s[i] <= '9'){
        v.push_back ((int)s[i]-'0');
      }
      else{
        ans += solver (v);
        v.clear();
      }
    }
    
    if (v.size())
      ans += solver (v);
    

    cout << ans << endl;
  }
  
  return 0;
}
