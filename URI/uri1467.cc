#include <iostream>

using namespace std;

int main (){
  
  while (true){
    int a, b, c;
    cin >> a >> b >> c;

    if (not cin) break;

    if (a == b and a != c)
      cout << "C\n";
    else if (a == c and a != b)
      cout << "B\n";
    else if (a != c and b == c)
      cout << "A\n";
    else
      cout << "*\n";
  }

  return 0;
}
