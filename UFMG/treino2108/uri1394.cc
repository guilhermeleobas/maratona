#include <iostream>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <stack>
#include <locale>
#include <cstdio>
#include <cctype>
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
  
  while (true){
    int n, m, g;
    cin >> n >> m >> g;
    if (n == 0 and m == 0 and g == 0)
      break;
    
    vector<vector<int> > v (n, vector<int> (n, 0));
    vector<int> points (n, 0);
    int total_games = ((n*n - n)/2) * m;
    int graph_size = total_games + 2 + n;
    int team_games = (n-1)*m;
    int zero_games = 0;
    for (int i=0; i<g; i++){
      int a, b;
      char type;
      cin >> a >> type >> b;
      
      v[a][b]++;
      v[b][a]++;
      
      if (type == '<'){
        points[b] += 2;
      }
      else {
        points[a]++;
        points[b]++;
      }
      
      if (a == 0 or b == 0)
        zero_games += 1;
      
    }
    /*
    graph_size = total_games + 2 + n;
    graph_size -= g-1;
    graph_size -= (n-1)*m - zero_games;
    */
    
    int missing_games=0;
    for (int j=1; j<n; j++){
      while (v[0][j] < m){
        missing_games++;
        v[0][j]++;
      }
    }
    
    Dinic d (graph_size);
    
    bool invalid = false;
    
    for (int i=1; i<n; i++){
      //d.addEdge (i, graph_size-1, zero_points + (team_games - zero_games)*2 - 1); 
      if (points[0] + missing_games*2 - points[i] - 1 < 0){
        cout << "N\n";
        invalid = true;
        break;
      }
      else {
        d.addEdge (i, graph_size-1, points[0] + missing_games*2 - points[i] - 1);
      }
    }
    
    if (invalid)
      continue;
   
    int total_points = 0;
    int cnt = n;
    for (int i=1; i<v.size(); i++){
      for (int j=1; j<i; j++){
        if (i == j) continue;
        
        while (v[i][j] < m){
          d.addEdge (cnt, i, 0x3f3f3f3f);
          d.addEdge (cnt, j, 0x3f3f3f3f);
          
          d.addEdge (0, cnt, 2);
          total_points+=2;
          cnt++;
          
          v[i][j] += 1;
          v[j][i] += 1;
        }
      }
    }
    
    
    if (d.flow(0, graph_size-1) == total_points)
      cout << "Y" << endl;
    else
      cout << "N" << endl;
  }
  
  return 0;
}
