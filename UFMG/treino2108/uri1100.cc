#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<vector<int> > graph;

bool valid (int x1, int y1, int x2, int y2){
  if (abs(x1-x2) + abs(y1-y2) != 3)
    return false;
  
  if (x2 < 0 or x2 > 7)
    return false;
  
  if (y2 < 0 or y2 > 7)
    return false;
  
  return true;
}

int bfs (graph &g, int s, int d){
  queue<int> q;
  vector<int> visited (g.size());
  vector<int> cost (g.size(), 0x3f3f3f3f);
  q.push (s);
  cost[s] = 0;
  visited[s] = true;
  
  while (not q.empty()){
    int tail = q.front();
    q.pop();
    
    if (tail == d)
      break;
    
    for (int i=0; i<g[tail].size(); i++){
      int head = g[tail][i];
      if (visited[head])
        continue;

      if (cost[head] > cost[tail] + 1){
        cost[head] = cost[tail] + 1;
        q.push (head);
      }
    }
  }
  
  return cost[d];
}

void print (vector<vector<int> > &m){
  for (int i=0; i<m.size(); i++){
    for (int j=0; j<m.size(); j++){
      cout << m[i][j] << ' ';
    }
    cout << endl;
  }
}

int char_to_int (char a){
  return (int)a - 'a';
}

int ichar_to_int (char i){
  return (int)i - '0'-1;
}

int main (){

  graph g (8*8 + 100);
  map<pair<int, int>, int> mapa;
  
  for (int i=0; i<8; i++){
    for (int j=0; j<8; j++){
      mapa[make_pair(i, j)] = mapa.size();
    }
  }
  
  for (int i=0; i<8; i++){
    for (int j=0; j<8; j++){
      for (int k=-2; k<=2; k++){
        for (int z=-2; z<=2; z++){
          if (valid (i, j, i+k, j+z)){
            int tail = mapa[make_pair (i, j)];
            int head = mapa[make_pair (i+k, j+z)];
            g[tail].push_back (head);
          }
        }
      }
    }
  }
  
  
  while (true){
    string a, b;
    cin >> a >> b;
    if (not cin) break;
    
    int x1 = char_to_int (a[0]);
    int y1 = ichar_to_int (a[1]);
    int x2 = char_to_int (b[0]);
    int y2 = ichar_to_int (b[1]);
    
    cout << "To get from " << a << " to " << b << " takes ";
    cout << bfs (g, mapa[make_pair (x1, y1)], mapa[make_pair (x2, y2)]);
    cout << " knight moves." << endl;
  }
  return 0;
  
}
