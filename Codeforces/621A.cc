#include <iostream>
#include <cmath>

using namespace std;

int main (){
  
  int n;
  cin >> n;
  
  int v[100000 + 100];
  
  long long s = 0;
  int impar = -1;
  
  for (int i=0; i<n; i++){
    int aux;
    cin >> aux;
    s += aux;
   
    if (aux % 2 != 0){
      if (impar == -1){
        impar = aux;
      }
      else {
        if (impar > aux){
          impar = aux;
        }
      }
    }
  }
  
  if (s % 2 != 0){
    s -= impar;
  }
  
  cout << s << endl;
 
  return 0;
}	
