#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int left (vector<int> l, vector<int> r){
  int sum = 0;
  bool swp = true;
  while (true){
    if (swp){
      if (l.size() == 0)
        break;
      else{
        sum += *l.begin();
        l.erase (l.begin());
      }
    }
    else {
      if (r.size() == 0){
        break;
      }
      else {
        sum += *r.begin();
        r.erase (r.begin());
      }
    }
    
    swp = !swp;
  }
  return sum;
}

int main (){
  
  int n;
  cin >> n;
  
  vector<pair<int, int> > aa, bb;
  vector<int> a, b;
  
  for (int i=0; i<n; i++){
    int x, k;
    cin >> x >> k;
    if (x < 0){
      aa.push_back (make_pair (x, k));
    }
    else{
      bb.push_back (make_pair (x, k));
    }
  }
  
  sort (aa.begin(), aa.end());
  sort (bb.begin(), bb.end());
  
  for (int i=aa.size()-1; i>=0; i--){
    a.push_back (aa[i].second);
  }
  
  for (int i=0; i<bb.size(); i++){
    b.push_back (bb[i].second);
  }
  
  cout << max (left (a,b), left(b, a)) << endl; 
  
  return 0;
}
