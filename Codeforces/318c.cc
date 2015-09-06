#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

// MDC
//Recebe dois inteiros {a, b} e retorna o mdc(a, b);
long long int mdc (long long int numerador, long long int denominador){
  
  long long int resto=-1;
  long long int quociente=-1;
  
  while (resto != 0){
    //Quociente;
    quociente = numerador/denominador;
    
    //Resto;
    resto = numerador%denominador;
    
    //Reatribuição;
    numerador = denominador;
    
    //Garante que a atribuição do resto não será zero;
    if (resto != 0) {
      denominador = resto;
    }
  }
  
  return denominador;
}

long long int mmc (long long int numerador, long long int denominador){
  return (numerador*denominador)/mdc(numerador, denominador);
}

bool check (long long lmc, long long num){
  long long r = lmc/num;
  
  while (r != 1){
    if (r % 2 == 0)
      r /= 2;
    else if (r % 3 == 0)
      r /= 3;
    else
      return false;
  }
  
  return true;
}

long long div (long long num){
  while (true){
    if (num%2 == 0)
      num /= 2;
    else if (num%3 == 0)
      num /= 3;
    else
      break;
  }
  return num;
}

int main (){

  int n;
  cin >> n;
  vector<long long> v (n);
  
  for (int i=0; i<n; i++){
    cin >> v[i];
  }
  
  set<int> s;
  for (int i=0; i<n; i++){
    s.insert (div (v[i]));
  }
  
  if (s.size() == 1)
    cout << "Yes\n";
  else
    cout << "No\n";
  
  return 0;
}
