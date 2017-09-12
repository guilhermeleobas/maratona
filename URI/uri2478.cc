#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<vector<int> > graph;

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f

int main (){
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  
  int n;
  cin >> n;
  
  map<string, vector<string> > mapa;
  
  for (int i=0; i<n; i++){
    string s, a, b, c;
    cin >> s >> a >> b >> c;
    mapa[s] = vector<string>();
    mapa[s].push_back (a);
    mapa[s].push_back (b);
    mapa[s].push_back (c);
  }
  
  while (true){
    string a, b;
    cin >> a;
    if (not cin)
      break;
    
    cin >> b;
    
    bool found = false;
    
    for (int i=0; i<mapa[a].size(); i++){
      if (mapa[a][i] == b){
        cout << "Uhul! Seu amigo secreto vai adorar o/" << endl;
        found = true;
        break;
      }
    }
    
    if (!found)
      cout << "Tente Novamente!" << endl;
  }
  
  return 0;
}
