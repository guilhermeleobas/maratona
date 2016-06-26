#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <stack>

using namespace std;

typedef vector<vector<int> > graph;

long long ans[100000 + 100];
int visited[100000 + 100];
int colors[100000 + 100];

void select_ans (unordered_map<int, int>* mapa, int x){
  int m = std::max_element
    (
     mapa->begin(), mapa->end(),
     [] (const pair<int,int> & p1, const pair<int, int> & p2) {
      return p1.second < p2.second;
     }
    )->second;
  
  for (auto it = mapa->begin(); it != mapa->end(); it++){
    if (it->second == m){
      ans[x] += it->first;
    }
  }
}

void print (unordered_map<int, int> *mapa){
  for (unordered_map<int, int>::iterator it = mapa->begin(); it != mapa->end(); it++){
    cout << it->first << ' ' << it->second << endl;
  }
  cout << endl;
}

void merge_maps (unordered_map<int, int> *a, unordered_map<int, int> *b){
  for (auto it = b->begin(); it != b->end(); it++){
    a->operator[](it->first) += it->second;
  }
}

unordered_map<int, int>* dfs (const graph &g, int x){
  
  visited[x] = true;
  unordered_map<int, int>* mapa = new unordered_map<int, int>();
  mapa->insert (make_pair (colors[x], 1));
 
  for (int i=0; i<g[x].size(); i++){
    int y = g[x][i];
    if (visited[y]) continue;
    unordered_map<int, int>* aux = dfs (g, y);
    
    if (aux->size() > mapa->size()){
      auto* x = aux;
      aux = mapa;
      mapa = x;
    }
    
    merge_maps (mapa, aux);
  }
  
  
  select_ans (mapa, x);
  
  return mapa;
}

int main (){
  int n;
  ios::sync_with_stdio(false);
  cin >> n;
  
 
  for (int i=0; i<n; i++){
    cin >> colors[i];
  }
  
  graph g(n);
  
  for (int i=0; i<n-1; i++){
    int x, y;
    cin >> x >> y;
    x--; y--;
    g[x].push_back (y);  
    g[y].push_back (x);
  }
  
  for (int i=0; i<n; i++){
    if (not visited[i])
      dfs (g, i);
  }
  
  for (int i=0; i<n; i++){
    cout << ans[i] << ' ';
  }
  cout << endl;
  
  return 0;
}
