#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <iomanip>
#include <stack>

using namespace std;

#define INF 0x3f3f3f3f
#define MAX 1000 + 10

int m[MAX][MAX], aux[MAX][MAX];
int state[MAX][MAX];
int soma[MAX][MAX];

int dp(int j, int l, int t){
  if (j == 0)
    return 0;
  
  if (state[j][l] != INF)
    return state[j][l];
  
  int s = soma[l][j];
  // for (int i=0; i<=l; i++)
  //   s += m[i][j];
  
  int r = dp(j-1, l, t) + s;
  
  for (int i=l+1; i<=(t-j+1); i++){
    int s = soma[i][j];
    // for (int k=0; k<=i; k++)
    //   s += m[k][j];
    r = max(r, dp(j-1, i, t) + s);
  }
  
  state[j][l] = r;
  return r;
}

int gen_soma(int t){
  for (int i=1; i<=t; i++){
    for (int j=1; j<=t; j++){
      soma[i][j] = soma[i-1][j] + m[i][j];
    }
  }
}

int main (){
  
  cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
  
  while (true){
    int t;
    cin >> t;
    
    if (t == 0) break;
    
    for (int i=1; i<=t; i++){
      for (int j=1; j<=i; j++){
        cin >> aux[i][j];
      }
    }
    
    for (int i=0; i<=t; i++)
      for (int j=0; j<=t; j++)
        m[i][j] = 0, state[i][j] = INF;
    
    
    int k = 0;
    for (int j=1; j<=t; j++){
      for (int i=1; i<=t-j+1; i++){
        m[i][j] = aux[i+k][j];
      }
      k++;
    }
    
    gen_soma(t);
    cout << dp(t, 0, t) << endl;
    
  }
  
  return 0;
}
