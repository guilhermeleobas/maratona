#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

typedef vector<vector<int> > tree;

void print (vector<vector<int> > &t){
  for (int i=0; i<t.size(); i++){
    cout << i+1 << ':' << ' ';
    for (int j=0; j<t[i].size(); j++){
      cout << t[i][j]+1 << ' ';
    }
    cout << endl;
  }
}

vector<int> cnt;
int count_child(const tree &t, int v){
  
  if (t[v].size() == 0){
    return cnt[v];
  }
  
  for (int i=0; i<t[v].size(); i++){
    cnt[v] += count_child(t, t[v][i]);
  }
  return cnt[v];
}

int dfs (const tree &t, int n, int v){
  
  int m = -1;
  int id = -1;
  
  for (int i=0; i<t[v].size(); i++){
    int c = t[v][i];
    // cout << "child " << c << " com cnt " << cnt[c] << endl;
    if (cnt[c] > m){
      m = cnt[c];
      id = c;
    }
    // cout << "m: " << m << " id: " << id << endl;
  }
  
  if (id == -1){
    return v;
  }
  else {
    if (m > n/2)
      return dfs (t, n, id);
    else
      return v;
  }
  

}

vector<int> s;
void preprocess (const tree &t, int v){
  
  if (t[v].size() == 0){
    s[v] = v;
    return;
  }
  
  int m = -1;
  int id = -1;
  for (int i=0; i<t[v].size(); i++){
    preprocess(t, t[v][i]);
    
    int c = t[v][i];
    if (cnt[c] > m){
      m = cnt[c];
      id = c;
    }
  } 
  
  if (m > cnt[v]/2){
    s[v] = s[id];
  }
  else {
    s[v] = v;
  }
}

int main (){

  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  
  vector<vector<int> > t(n, vector<int>());
  cnt.resize(n, 1);
  s.resize (n);
  
  for (int i=0; i<n-1; i++){
    int x;
    cin >> x;
    t[x-1].push_back (i+1);
  }
  
  // print (t);
  count_child(t, 0); 
  // preprocess(t, 0);
  // for (int i=0; i<cnt.size(); i++){
  //   cout << cnt[i] << ' ';
  // }
  // cout << endl;
  map<int, int> qq;
  
  for (int i=0; i<q; i++){
    int id;
    cin >> id;
    // cout << s[id-1]+1 << endl;
    if (qq.find(id-1) == qq.end())
      qq[id-1] = dfs (t, cnt[id-1], id-1)+1;
    cout << qq[id-1] << endl;
  }
  return 0;
}
