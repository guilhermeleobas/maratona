#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main (){
  
  int k;
  string s;

  cin >> k >> s;
  
  set<char> se;
  string atual;
  vector<string> ans;
  for (int i=0; i<s.size(); i++){
    if (se.find (s[i]) == se.end()){
      if (atual.size() > 0){
        ans.push_back (atual);
        atual = "";
      }
      atual += s[i];
      se.insert (s[i]);
    }
    else {
      atual += s[i];
    }
  }

  ans.push_back (atual);

  if (ans.size() < k){
    cout << "NO\n";
  }
  else {
    cout << "YES\n";
    if (ans.size() > k){
      for (int i=k; i<ans.size(); i++)
        ans[k-1] += ans[i];
    }

    for (int i=0; i<k; i++){
      cout << ans[i] << '\n';
    }
  } 
  
  return 0;
}
