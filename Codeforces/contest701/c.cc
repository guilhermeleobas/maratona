#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void print (const map<char, int> m){
  for (auto i = m.begin(); i != m.end(); i++)
    cout << i->first << ' ' << i->second << endl;
  cout << endl;
}

int main (){
  
  int n;
  cin >> n;
  string s;
  cin >> s;
  
  int left = 0;
  int right = -1;
  
  set<char> ss;
  map<char, int> m;
  for (int i=0; i<s.size(); i++){
    ss.insert(s[i]);
    m[s[i]] = 0;
  }
  int unique = ss.size();

  int desired = 0;
  int ans = 0x3f3f3f3f;
  int cnt = 0;
  
  while (true){
    // cout << left << ' ' << right << ' ' << desired << ' ' << unique << endl;
    // print (m);
    
    while (right < n and desired < unique){
      
      right++;
      
      if (right >= n)
        break;
      
      // cout << "entrou aqui" << endl;
      // cout << right << ' ' << n << ' ' << (right < n) << endl;
      // cout << desired << ' ' << unique << ' ' << (desired < unique) << endl;
      // cout << endl;
      
      m[s[right]] += 1;
      
      if (m[s[right]] == 1){
        desired++;
      }
      
    }
    
    // cout << left << ' ' << right << ' ' << desired << ' ' << unique << endl;
    // print (m);

    if (desired == unique)
      ans = min (right-left+1, ans);
    
    if (left < right){
      char c = s[left];
      
      m[c] -= 1;
      
      // cout << "decrementou " << c << " para " << m[c] << endl;
      
      if (m[c] == 0)
        desired -= 1;
      
      left += 1;
    }
    else {
      if (right + 1 >= n)
        break;
      
      right += 1;
      char c = s[right];
      m[c] += 1;
      
      if (m[c] == 1)
        desired += 1;
    }
    
    if (desired == unique)
      ans = min (right-left+1, ans);
    

    // cout << left << ' ' << right << ' ' << desired << ' ' << unique << endl;
    // print (m);
    
    // cout << "-----\n";

    // break;
    
  }
  
  cout << ans << endl;
  
  
  return 0;
}
