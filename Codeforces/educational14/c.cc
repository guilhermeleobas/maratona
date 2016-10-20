#include <iostream>
#include <tuple>
#include <string>

using namespace std;

pair<string, string> split(string s){
  string a, b;
  
  bool invert = false;
  for (int i=0; i<s.size(); i++){
    if (s[i] == '.'){
      invert = true;
      continue;
    }
    
    if (not invert)
      a += s[i];
    else
      b += s[i];
  }
  
  while (a.size() > 0 and a.front() == '0')
    a.erase(a.begin());
  
  while (b.size() > 0 and b.back() == '0')
    b.pop_back();
  
  return make_pair(a, b);
}

int main (){
  
  string s;
  cin >> s;
  
  pair<string, string> p = split(s);
  
  int len = p.first.size() - 1;
  
  string b;
  
  for (int i=1; i<p.first.size(); i++){
    b += p.first[i];
  }
  
  bool valid = false;
  for (int i=0; i<b.size(); i++){
    if (b[i] != '0')
      valid = true;
  }
  
  if (not valid)
    b.clear();
  
  b += p.second;
  
  while (p.first.size() == 0 and b.size() > 0 and b[0] == '0'){
    b.erase(b.begin());
    len -= 1;
  }
  
  while (b.size() > 0 and b.back() == '0'){
    b.pop_back();
  }
  
  if (p.first.size() == 0 and p.second.size() == 0){
    cout << '0' << endl;
  }
  else if (b.size() == 0 and p.first.size() == 1){
    cout << p.first << endl;
  }
  else {
    if (p.first.size() != 0)
      cout << p.first[0];
    
    if (p.first.size() != 0 and b.size() != 0)
      cout << '.';
    
    cout << b;
    
    if (len != 0)
      cout << 'E' << len;
    
    cout << endl;
  }
  
  return 0;
}
