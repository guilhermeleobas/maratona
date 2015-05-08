#include <iostream>
#include <vector>

using namespace std;

long long get (int i, int j){
  
  long long ans = 0;

  ans = 1 + (i-j)*(j);

  return ans;
}

int main (){
  
  int p;

  cin >> p;

  for (int i=0; i<p; i++){
    int id, n,m;
    cin >> id >> n >> m;

    cout << id << ' ' <<  get (n, m) << endl;
  }

  return 0;
}
