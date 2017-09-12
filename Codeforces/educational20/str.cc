#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main (){
  
  string a, b;
  cin >> a >> b;
  
  string ret;
  
  int i = 0, j = 0;
  
  while (i < a.size() and j < b.size()){
    ret += a[i++];
    ret += b[j++];
  }
  
  while (i < a.size())
    ret += a[i++];
  
  while (j < b.size())
    ret += b[j++];
  
  cout << ret << endl;
  
  return 0;
}
