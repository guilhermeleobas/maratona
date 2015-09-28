#include <iostream>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <locale>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define endl "\n"
typedef long long int ll;
const int MAXN=5000;

class Dinic
{
 private:
  typedef struct sedge
  {
    int a, b; ll cap, flow;
    sedge(int _a, int _b, ll _cap, ll _flow)
    { a=_a; b=_b; cap=_cap; flow=_flow; }
  } edge;
  
  // Number of vertices, source, sink, visited, queue
  int n, s, t, d[MAXN], q[MAXN];
  int ptr[MAXN];
  vector<edge> vEdges;
  vector<int> g[MAXN];
    
  
  bool bfs()
  {
    int qh=0, qt=0;
    q[qt++]=this->s;
    memset(this->d, -1, n*sizeof(d[0]));
    this->d[this->s]=0;
    while(qh < qt && d[this->t] == -1)
    {
      int v=q[qh++];
      for(size_t i=0; i<g[v].size(); i++)
      {
        int id = g[v][i], to=vEdges[id].b;
        if(d[to]==-1 && vEdges[id].flow < vEdges[id].cap)
        { q[qt++]=to; d[to]=d[v]+1; }
      }
    }
    return d[t]!=-1;
  }
  
  ll dfs(int v, ll flow)
  {
    if(!flow) return 0;
    if(v == t) return flow;
    for(; ptr[v] < (int)g[v].size(); ptr[v]++)
    {
      int id=g[v][ptr[v]], to=vEdges[id].b;
      
      // If v did not find to on the bfs...
      if(d[to]!=d[v]+1) continue;
      
      ll pushed=dfs(to, min(flow, vEdges[id].cap-vEdges[id].flow));
      if(pushed)
      {
        vEdges[id].flow+=pushed;
        vEdges[id^1].flow-=pushed;
        return pushed;
      }
    }
    return 0;
  }
  

 public:
  
  Dinic()
  { this->init(0); }

  Dinic(int _n)
  { this->init(_n); }

  void init(int _n)
  {
    this->clear();
    this->n=_n;
  }

  void clear()
  {
    this->vEdges.clear();
    for(int i=0; i < MAXN; i++) g[i].clear();
  }

  void addEdge(int from, int to, ll cap)
  {
    edge e1(from, to, cap, 0);
    edge e2(to, from, 0, 0);
    
    g[from].push_back((int)vEdges.size());
    vEdges.push_back(e1);
    g[to].push_back((int)vEdges.size());
    vEdges.push_back(e2);
  }
  
  ll flow(int source, int sink)
  {
    this->s=source;  this->t=sink;
    ll flow=0;

    while(true)
    {
      if(not bfs()) break;
      memset(ptr, 0, n*sizeof(ptr[0]));
      while(int pushed=dfs(s, INF))
        flow+=pushed;
    }
    return flow;
  }
};

int main (){
  
  int instance = 1;
  while (true){
    int n, m, k;
    cin >> n >> m >> k;
    if (not cin) break;

    int sz = 2 + n + m;
    Dinic dinic (sz);
    
    vector<int> vec (n);
    for (int i=0; i<n; i++)
      cin >> vec[i];
    
    for (int i=1; i<=m; i++){
      dinic.addEdge (0, i, 1);
    }
    
    for (int i=1; i<=n; i++){
      dinic.addEdge (m+i, sz-1, vec[i-1]); 
    }
    
    for (int i=0; i<k; i++){
      int u, v;
      cin >> u >> v;
      
      dinic.addEdge (v, u+m, 1);
    }
    
    int flow = dinic.flow (0, sz-1);
    cout << "Instancia " << instance++ << endl; 
    cout << flow << endl << endl;
  }
  
  return 0;
}

