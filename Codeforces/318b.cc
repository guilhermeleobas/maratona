#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<vector<int> > graph;

int main (){
  
  int n, m;
  cin >> n >> m;
  
  graph v (n, vector<int> (n, 0));
  vector<pair<int, int> > p;
  vector<int> sum (n, 0);
  for (int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    p.push_back (make_pair (a, b));
    v[a][b] = 1;
    v[b][a] = 1;
    sum[a]++;
    sum[b]++;
  }
  
  int ans = 0x3f3f3f3f;
  
  for (int i=0; i<p.size(); i++){
    int a = p[i].first;
    int b = p[i].second;
    
    for (int j=0; j<n; j++){
      if (v[a][j] and v[b][j] and v[a][b]){
        ans = min (ans, sum[a] + sum[b] + sum [j] - 6);
      }
    }
  }
  
  
  if (ans == 0x3f3f3f3f)
    cout << "-1\n";
  else
    cout << ans << endl;
  
  return 0;
}
