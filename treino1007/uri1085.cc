#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class wrapper {
 public:
  int size, country_code;
  char first_letter;
   
  wrapper (int size, int country_code, char first_letter):
    size (size), country_code (country_code), first_letter (first_letter)
  {
    // 
  }
  
  bool operator < (const wrapper& other) const {
    return size > other.size;
  }
  
};

typedef vector<vector<wrapper> > graph;

int dijkstra (graph &g, int source, int destiny){
  int n = g.size();
  set<pair<int, char> > visited;
  priority_queue<wrapper> pq;
  
  pq.push (wrapper (0, source, '0'));
  
  while (not pq.empty()){
    wrapper w = pq.top();
    pq.pop();
    
    int cc = w.country_code;
    
    if (cc == destiny){
      return w.size;
    }
    
    if (visited.find (make_pair (w.country_code, w.first_letter)) != visited.end())
      continue;
    
    visited.insert (make_pair (w.country_code, w.first_letter));
    for (int i=0; i<g[cc].size(); i++){
      wrapper next = g[cc][i];
      if (visited.find (make_pair (next.country_code, next.first_letter)) != visited.end()) 
        continue;
      
      if (next.first_letter == w.first_letter)
        continue;
      
      next.size += w.size;
      pq.push (next);
    }
    
  }
  
  return -1;
} 

int main (){
  
  while (true){
    int n;
    cin >> n;

    if (n == 0)
      break;

    graph g (n);
    map<string, int> m;
    string s, t;
    cin >> s >> t;
    for (int i=0; i<n; i++){
      string c1, c2, word;
      cin >> c1 >> c2 >> word;
      if (m.find (c1) == m.end())
        m[c1] = m.size();
      if (m.find (c2) == m.end())
        m[c2] = m.size();
      
      if (m.size() >= g.size())
        g.resize (m.size()+1);
        
      g[m[c1]].push_back (wrapper (word.size(), m[c2], word[0]));
      g[m[c2]].push_back (wrapper (word.size(), m[c1], word[0]));
    }
    
    int ans = dijkstra (g, m[s], m[t]);
    if (ans == -1 or ans == 0)
      cout << "impossivel\n";
    else
      cout << ans << endl;
        
  }

  return 0;
}
