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

#define EPS 1e-7
#define INF 2147483000
#define MAX 1024 //5000

class Dinic{
  private:
    vector<vector<int> > adj, graph;

  public:
    Dinic(){}
    Dinic(int n);
    void init(int n);
    void clear();
    void addEdge(int from, int to, int capacity);
    long long flow(int source, int sink);
};

Dinic::Dinic(int n)
{ this->init(n); }

void Dinic::init(int n)
{
  this->graph.clear();
  this->adj.clear();
  this->adj.resize(n);
  this->graph.resize(n, vector<int>(n, 0));
}

void Dinic::clear()
{
  this->graph.clear();
  this->adj.clear();
}

void Dinic::addEdge(int from, int to, int capacity)
{
  if(this->graph[from][to]==0) this->adj[from].push_back(to);
  this->graph[from][to]+=capacity;
}

long long Dinic::flow(int source, int sink)
{
  int pathCap=0, atual=0, bottleneck=0;
  queue<int> q;
  vector<int> previous(graph.size(), -1);
  
  while(true)
  {
    q.push(source);
    previous.clear();
    previous.resize(graph.size(), -1);
    previous[source] = -2;
    
    while(!q.empty() && previous[sink] == -1)
    {
      atual = q.front();
      q.pop();
      for(unsigned int i = 0; i < this->adj[atual].size(); i++)
        if(previous[adj[atual][i]] == -1 && this->graph[atual][adj[atual][i]])
        { q.push(this->adj[atual][i]); previous[adj[atual][i]] = atual; }
    }
    
    if(previous[sink] == -1) break;
    while(!q.empty()) q.pop();
    
    for(int i = 0; i < this->graph.size(); i++) if(this->graph[i][sink] && previous[i] != -1)
    {
      bottleneck = this->graph[i][sink];
      for(int v = i, u = previous[v]; u >= 0; v = u, u = previous[v])
        bottleneck = min(bottleneck, this->graph[u][v]);
      
      if(!bottleneck) continue;
      
      this->graph[i][sink] -= bottleneck;
      this->graph[sink][i] += bottleneck;
      
      for(int v = i, u = previous[v]; u >= 0; v = u, u = previous[v])
      {
        this->graph[u][v] -= bottleneck;
        this->graph[v][u] += bottleneck;
      }
      pathCap+=bottleneck;
    }
  }
  return pathCap;
}


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
    int zero_points = 0;
    int zero_games = 0;
    for (int i=0; i<g; i++){
      int a, b;
      char type;
      cin >> a >> type >> b;
      
      v[a][b]++;
      v[b][a]++;
      
      if (type == '<'){
        points[b] += 2;
        if (b == 0)
          zero_points += 2;
      }
      else {
        points[a]++;
        points[b]++;
        if (a == 0 or b == 0)
          zero_points += 1;
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
    
    for (int i=1; i<n; i++){
      //d.addEdge (i, graph_size-1, zero_points + (team_games - zero_games)*2 - 1); 
      d.addEdge (i, graph_size-1, zero_points + missing_games*2 - 1);
    }
    
   
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
