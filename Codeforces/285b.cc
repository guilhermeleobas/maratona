#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main (){
  
  int n;
  cin >> n;
  vector<pair<string, string> > v (n);

  for (int i=0; i<n; i++)
    cin >> v[i].first >> v[i].second;


  map<string, bool> m;
  for (int i=0; i<n; i++){
    m[v[i].first] = false;
    m[v[i].second] = false;
  }

  vector<string> result;
  for (int i=0; i<n; i++){
    string a = v[i].first;
    string b = v[i].second;
    if (m[a]) continue;
    result.push_back (a);
    m[a] = true;
    for (int j=i+1; j<n; j++){
      if (v[j].first == b){
        b = v[j].second;
        m[v[j].first] = true;
      }
    }
    m[b] = true;
    result.push_back (b);
  }
  
  cout << result.size()/2 << endl;

  for (int i=0; i<result.size(); i++){
    cout << result[i] << ' ' << result[i+1] << endl;
    i+= 1;
  }
}
