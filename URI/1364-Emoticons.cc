#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>


using namespace std;

bool match (const string &s, const string &e, int i){
  
  for (int j=0; j<e.size(); j++){
    if (i-j < 0) return false;
    
    if (e[j] != s[i-j]){
      // cout << "falhou com: " << e << ' ' << s[i-j] << endl;
      return false;
    }
  }
  
  return true;
}

int check(const vector<string> &v, string &s){
  int ans = 0;
  
  vector<int> c (s.size(), 0);
  for (int i=0; i<s.size(); i++){
    for (auto &e : v){
      if (e[0] == s[i]){
        c[i] = 1;
      }
    }
  }
  
  for (int i=0; i<s.size(); i++){
    if (!c[i]) continue;
    
    for (auto &e : v){
      if (match (s, e, i)){
        // cout << "deu match: " << e << ' ' << s[i] << endl;
        // i -= e.size() - 1;
        s[i] = ' ';
        ans += 1;
        break;
      }
    }
  }
  return ans;
}

int main (){
  
  while (true){

    int n, m;
    cin >> n >> m;
    
    if (n == 0 and m == 0)
      break;
    
    int ans = 0;
    
    vector<string> v;
    for (int i=0; i<n; i++){
      string s;
      cin >> s;
      cin.ignore();
      // cout << "leu: " << s << endl;
      reverse(s.begin(), s.end());
      v.push_back(s);
    }
    
    for (int i=0; i<m; i++){
      string s;
      getline(cin, s);
      // cout << "leu: " << s << endl;
      
      ans += check(v, s);
    }
    
    // sort(begin(v), end(v), 
    //     [](const string &a, const string &b){
    //       return a.size() < b.size();
    //     });
    
    //sort(v.begin(), v.end());
    cout << ans << endl;
    
    
  }
}
