#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool check_line(const vector<string> &v){
  
  int sz = 1;
  
  for (int i=1; i<v.size(); i++)
    if (v[i] == v[i-1]) 
      sz++;
    else
      break;
  
  for (int j=0; j<v[0].size(); j++){
    int p = 1;
    set<char> s;
    s.insert(v[0][j]);
    for (int i=1; i<v.size(); i++){
      
      s.insert(v[i][j]);
      
      if (j > 0 and v[i][j] != v[i][j-1])
        return false;
      
      if (v[i][j] == v[i-1][j])
        p++;
      else{
        if (p != sz)
          return false;
        else
          p = 1;
      }
    }
    
    if (p != sz) return false;
    if (s.size() != 3) return false;
    s.clear();
  }
  
  return true;
}

int main (){

  int n, m;
  
  cin >> n >> m;
  
  vector<string> v(n);
  vector<string> rev(m, string(n, 'a'));
  
  for (int i=0; i<n; i++){
    cin >> v[i];
  }
  
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      rev[j][i] = v[i][j];
    }
  }
  
  // for (int i=0; i<v.size(); i++){
  //   cout << v[i] << endl;
  // }
  // cout << check_line(v) << endl;
  //
  // cout << endl;
  //
  // for (int i=0; i<rev.size(); i++){
  //   cout << rev[i] << endl;
  // }
  // cout << check_line(rev) << endl;
  
  if (check_line(v) or check_line(rev))
    cout << "YES\n";
  else
    cout << "NO\n";
}
