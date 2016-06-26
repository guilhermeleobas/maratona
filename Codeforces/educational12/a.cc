#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>

using namespace std;


int count (int h, int m, int ta, int b, int tb){
  int x1 = h*60 + m;
  int y1 = x1 + ta;
  int ans = 0;
  
  for (int i = 5*60; i < 60*24; i += b){
    int x2 = i;
    int y2 = x2 + tb;
    
    if (max(x1, x2) < min(y1, y2))
      ans++;
  }
  return ans;
}

int main (){

  int a, ta, b, tb;
  cin >> a >> ta >> b >> tb;
  int h, m;
  
  string s;
  cin >> s;
  
  h = 10 * ((s[0]) - '0');
  h += (s[1]) - '0';
  
  m = 10*(s[3]-'0') + (s[4]-'0');
  
  cout << count (h, m, ta, b, tb) << endl;
  return 0;
}
