// http://codeforces.com/gym/100676/attachments/download/3333/acm-arabella-collegiate-programming-contest-en.pdf

#include <iostream>
#include <string>

using namespace std;

int main (){
  int n;
  cin >>n;
  while (n--){
  int a, b;
  string op;
  string t = "true", f = "false";
  
  cin >> a >> op >> b;
  
  if (op == "!="){
    if (a != b) cout << t << endl;
    else cout << f << endl;
  }
  else if (op == "=="){
    if (a == b) cout << t << endl;
    else cout << f << endl;
  }
  else if (op == "<"){
    if (a < b) cout << t << endl;
    else cout << f << endl;
  }
  else if (op == ">"){
    if (a > b) cout << t << endl;
    else cout << f << endl;
  }
  else if (op == "<="){
    if (a <= b) cout << t << endl;
    else cout << f << endl;
  }
  else if (op == ">="){
    if (a >= b) cout << t << endl;
    else cout << f << endl;
  }
  }
  return 0;
}
