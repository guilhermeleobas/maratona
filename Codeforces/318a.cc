#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int main (){

  int n;
  cin >> n;
  
  int limak;
  cin >> limak;
  int maior = 0;
  priority_queue<int, vector<int>, less<int> > pq;
  for (int i=1; i<n; i++){
    int aux;
    cin >> aux;
    pq.push (aux);
  }
  
  
  int ans = 0;
  
  while (true){
    maior = pq.top();
    pq.pop();
    if (limak > maior)
      break;
    else{
      limak++;
      maior--;
      ans++;
      pq.push (maior);
    }
  }
  
  cout << ans << endl;
  return 0;
}
