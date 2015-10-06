#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){

  int na, nb, k, m;
  cin >> na >> nb >> k >> m;
  vector<int> a (na), b (nb);
  
  for (int i=0; i<na; i++)
    cin >> a[i];
  for (int i=0; i<nb; i++)
    cin >> b[i];
  
  int minimo = a[k-1];

  int pos = upper_bound (b.begin(), b.end(), minimo) - b.begin();

  if (nb - pos >= m)
    cout << "YES\n";
  else
    cout << "NO\n";
  
  return 0;
}
