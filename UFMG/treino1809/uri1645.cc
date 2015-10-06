#include <iostream>
#include <vector>

using namespace std;

long long get (vector<vector<long long> > f, vector<int> v, int n, int k){
  long long sum = 0;
  
  for (int i=1; i<n; i++){
    if (v[n] > v[i])
      sum += f[i][k-1];
  }
  
  return sum;
}

void print (vector<vector<long long> > f){
  for (int i=0; i<f.size(); i++){
    for (int j=0; j<f[i].size(); j++){
      cout << f[i][j] << ' ';
    }
    cout << endl;
  }
}

long long solver (vector<vector<long long> > f, vector<int> v, int n, int k){
  
  for (int i=1; i<=n; i++){
    f[i][1] = 1;
  }
  for (int i=2; i<=n; i++){
    for (int j=2; j<=k; j++){
      f[i][j] = get (f, v, i, j);
    }
  }
  
  long long sum = 0;
  
  for (int i=k; i<=n; i++)
    sum += f[i][k];
  
  return sum;
  
}

int main (){

  while (true){
    int n, k;
    cin >> n >> k;
    
    if (n == 0 and k == 0) break;
    
    vector<int> v (n+1, 0);
    
    for (int i=1; i<=n; i++)
      cin >> v[i];
    
    vector<vector<long long> > f (n+10, vector<long long> (k+10, 0));
  
    cout << solver (f, v, n, k) << endl;
    
  }
  return 0;
}
