#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main (){

  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;

  vector<pair<int, int> > v(2*n);

  for (int i=0; i<n; i++){
    int a, b;
    cin >> a >> b;
    v[2*i] =  (make_pair (a, -1));
    v[2*i + 1] = (make_pair (b, 1));
  }

  sort (v.begin(), v.end());

  vector<pair<int, int> > ans;
  int aux = 0;
  int l = 0, r = 0;

  for (int i=0; i<v.size(); i++){
    if (v[i].second == -1) aux += 1;
    else aux -= 1;

    if (aux == k and v[i].second == -1) l = v[i].first;
    if (aux == k-1 and v[i].second == 1){
      r = v[i].first;
      ans.push_back (make_pair (l, r));
    }

  }

  cout << ans.size() << endl;
  for (int i=0; i<ans.size(); i++){
    cout << ans[i].first << ' ' << ans[i].second << endl;
  }


  return 0;
}
