#include <string>
#include <iostream>
#include <vector>

using namespace std;

int ss (char i){
  if (i == '0' or i == '6' or i == '9')
    return 6;
  else if (i == '4')
    return 4;
  else if (i == '1')
    return 2;
  else if (i == '2' or i == '3' or i == '5')
    return 5;
  else if (i == '7')
    return 3;
  else if (i == '8')
    return 7;
}

int main (){
  
  int t;
  cin >> t;
  while (t--){
    string s;
    cin >> s;

    long long sum = 0;

    for (int i=0; i<s.size(); i++)
      sum += ss (s[i]);
    cout << sum << " leds" << endl;

  }
  
  return 0;
}
