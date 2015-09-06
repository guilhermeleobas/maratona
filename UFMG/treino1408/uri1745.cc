#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

long long process (string aux){
  long long ans = 0;
  long long s0 = 0, s1 = 0, s2 = 0;
  
  for (int i=0; i<aux.size(); i++){
    int num = int(aux[i]) - '0';
    int aux2 = s2;
    int aux1 = s1;
    int aux0 = s0;
    
    if(num%3 == 0){
      s0++;
    }
    else if(num%3 == 1){
      s0 = aux2;
      s2 = aux1;
      s1 = aux0;
      s1++;
    }
    else {
      s1 = aux2;
      s0 = aux1;
      s2 = aux0;
      s2++;
    }
    ans += s0;
    
    //cout << s0 << ' ' << s1 << ' ' << s2 << ' ' << ans << endl;
  }
  
  return ans;
}

int main (){
  
  string input;
  cin >> input;
  
  string aux;
  long long ans = 0;
  for (int i=0; i<input.size(); i++){
    if (input[i] >= '0' and input[i] <= '9')
      aux.push_back (input[i]);
    else{
      if (aux.size())
        ans += process (aux);
      aux.clear();
    }
  }
  
  if (aux.size())
    ans += process(aux);
  cout << ans << endl;
  return 0;
}
