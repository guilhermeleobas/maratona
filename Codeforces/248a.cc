#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main (){

  int n;
  int sum = 0;

  cin >> n;
  int x = 0, y = 0;

  for (int i=0; i<n; i++){
    int aux = 0;
    cin >> aux;
    if (aux == 100)
      x++;
    else
      y++;
  }

  if (y % 2 == 0)
    y = 0;
  else
    y = 1;

  if (x >= 2 and x % 2 == 0 and y == 1){
    cout << "YES\n";
  }
  else if (y == 0 and x % 2 == 0){
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
  return 0;
}
