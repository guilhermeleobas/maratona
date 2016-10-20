#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

map<long long, long long> mapa;
void insert (long long vertex, long long w){
  if (mapa.find(vertex) == mapa.end())
    mapa[vertex] = w;
  else
    mapa[vertex] = mapa[vertex] + w;
}

long long query (long long vertex){
  if (mapa.find(vertex) == mapa.end())
    return 0;
  else
    return mapa[vertex];
}

void lca (long long u, long long v, long long w){
  while (u != v){
    if (u > v){
      insert(u, w);
      // cout << "mapa[" << u << "]: " << mapa[u] << endl;
      u = u/2;
    }
    else {
      insert (v, w);
      // cout << "mapa[" << v << "]: " << mapa[v] << endl;
      v = v/2;
    }
  }
}

int main (){

  int t;
  cin >> t;
  while (t--){
    int type;
    cin >> type;
    if (type == 1){
      long long u, v, w;
      cin >> u >> v >> w;
      lca (u, v, w);
    }
    else {
      long long u, v;
      cin >> u >> v;
      
      long long ans = 0;
      
      while (u != v){
        if (u > v){
          // cout << "query(" << u << ")" << ": " << query(u) << endl;
          ans += query (u);
          u = u/2;
        }
        else {
          // cout << "query(" << v << ")" << ": " << query(v) << endl;
          ans += query (v);
          v = v/2; 
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
