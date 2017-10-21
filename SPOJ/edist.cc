#include <bits/stdc++.h>

using namespace std;

#define MAX 2000+10
#define INF 0x3f3f3f3f

int dp[MAX][MAX];

int dist (const string &a, const string &b, int i, int j){

  // cout << "testando para " << i << ' ' << j << endl;

  if (i == a.size()){
    dp[i][j] = b.size() - j;
    return dp[i][j];
  }
  if (j == b.size()){
    dp[i][j] = a.size() - i;
    return dp[i][j];
  }


  if (dp[i][j] != INF){
    // cout << "return1 " << dp[i][j] << endl;
    return dp[i][j];
  }

  int aux = 0;
  if (a[i] != b[j]) aux = 1;

  int ans = min (dist(a, b, i+1, j+1) + aux,
              min(dist(a, b, i, j+1) + 1,
                  dist(a, b, i+1, j) + 1)
              );

  dp[i][j] = ans;
  // cout << "return4 " << i << ' ' << j << " : " << dp[i][j] << endl;
  return ans;
}

int main(){

  int t;
  cin >> t;

  while (t--){
    string a, b;
    cin >> a >> b;

    while (a.size() < b.size())
      if (a.size() < b.size())
        a += ' ';
      else
        b += ' ';

    for (int i=0; i<=a.size()+2; i++)
      for (int j=0; j<=b.size()+2; j++)
        dp[i][j] = INF;

    cout << dist (a, b, 0, 0) << endl;

    // for (auto &i : cache){
    //   cout << i.first.first << ' ' << i.first.second << " = " << i.second << endl;
    // }
  }

  return 0;
}
