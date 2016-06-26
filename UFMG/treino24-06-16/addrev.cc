// http://www.spoj.com/problems/ADDREV/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void reverse (string &s){
  int i=0, j=s.size()-1;
  
  while (i < j){
    swap (s[i], s[j]);
    i++;
    j--;
  }
}

int main (){

  int n;
  cin >> n;
  
  while (n--){
    string a, b;
    cin >> a >> b;
    
    reverse(a);
    reverse(b);
    int p = stoi(a);
    int q = stoi(b);
    string ans = to_string(p+q);
    reverse(ans);
      
    bool go = false;
    

    for (int i=0; i<ans.size(); i++){
      if (ans[i] != '0'){
        go = true;
      }
      
      if (go)
        cout << ans[i];
    }

    cout << endl;
  }
  
  return 0;
}
