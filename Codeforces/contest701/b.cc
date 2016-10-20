#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void print (set<long long> s){
  for (auto i=s.begin(); i != s.end(); i++){
    cout << *i << ' ';
  }
  cout << endl;
}

int main (){
  
  long long n, m;
  cin >> n >> m;
  
  set<long long> x;
  set<long long> y;
  
  long long s = n*n;
  
  for (int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    
    if (x.find(a) == x.end()){
      s -= n;
      s += y.size();
    }
    if (y.find(b) == y.end()){
      s -= n;
      s += x.size();
    }
    if (x.find(a) == x.end() and y.find(b) == y.end()){
      s += 1;
    }
    
    cout << s << ' ';
    // cout << s << endl;
    // cout << "print x ";
    // print(x);
    // cout << "print y ";
    // print(y);
    x.insert(a);
    y.insert(b);
    
  }
  cout << endl;
  
  
  
  return 0;
}
