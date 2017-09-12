#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

map<long long, long long> cache;

long long calc (long long x){
  if (cache.find(x) != cache.end())
    return cache[x];
  
  if (x == 1)
    return 1;
  
  cache[x] = 1 + (x % 2 != 0 ? calc (3*x+1) : calc(x/2));
  
  return cache[x];
}

int main (){

  while (true){
    long long x, y;
    cin >> x >> y;
    
    if (not cin)
      break;
    
    long long ans = -1;
    for (long long i=min(x, y); i<=max(x, y); i++){
      long long p = calc(i);
      if (ans < p){
        ans = p;
      }
    }
    
    cout << x << ' ' << y << ' ' << ans << endl;
  }
  
  return 0;
}
