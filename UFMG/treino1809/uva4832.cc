#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <map>

using namespace std;

class line {
 private:
  map<string, int> mapa;
  int sum;
 public:
  line (vector<string> v, int sum){
    for (int i=0; i<v.size(); i++)
      mapa[v[i]]++;
    
    this->sum = sum;
  }
  
  const int size () const{
    return mapa.size();
  }
  
  pair<string, int> get (){
    string s = mapa.begin()->first;
    return make_pair (s, sum/mapa[s]);
  }
  
  bool erase (string s, int value){
    if (mapa.find (s) == mapa.end())
      return false;
    
    while (mapa[s] > 0){
      sum -= value;
      mapa[s]--;
    }
    
    mapa.erase (s);
    return true;
  }
 
  bool operator < (const line& other) const{
    return mapa.size () < other.size();
  }
  
};

void solver (vector<line> s, set<string> ids){
  int pos = 0;
  map<string, int> ans;
  while (ids.size()){
    for (int i=0; i<s.size(); i++){
      if (s[i].size() == 1){
        pos = i;
        break;
      }
    }
    
    pair<string, int> p = s[pos].get (); 
    s.erase (s.begin() + pos);
    
    for (int i=0; i<s.size(); i++){
      s[i].erase (p.first, p.second);
    }
    
    ids.erase (p.first);
    ans[p.first] = p.second;
  }
  
  for (map<string, int>::iterator it = ans.begin(); it != ans.end(); it++){
    cout << it->first << ' ' << it->second << endl;
  }
}

int main (){
 
  while (true){
    int l, c;
    cin >> l >> c;
    if (not cin) break;
    
    vector<vector<string> > v (l);
    vector<line> conjunto;
    set<string> ids;
    for (int i=0; i<l; i++){
      int sum = 0;
      for (int j=0; j<c; j++){
        string s;
        cin >> s;
        ids.insert (s);
        v[i].push_back (s);
        if (j == c-1)
          cin >> sum;
      }
      conjunto.push_back (line(v[i], sum));
    }
    
    vector<int> c_sum;
    for (int i=0; i<c; i++){
      int aux;
      cin >> aux;
      c_sum.push_back (aux);
    }
    
    for (int i=0; i<c; i++){
      vector<string> column;
      for (int j=0; j<l; j++){
        column.push_back (v[j][i]);
      }
      conjunto.push_back(line(column, c_sum[i]));
    }
   
    solver (conjunto, ids);
  }
  return 0;
}
