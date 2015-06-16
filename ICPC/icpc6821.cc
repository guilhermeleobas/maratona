//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4833

#include <iostream>
#include <vector>

using namespace std;

int main (){

  while (true){
    vector<int> a (5);
    vector<int> b (5);
    
    cin >> a[0];
    if (not cin) break;
    for (int i=1; i<5; i++)
      cin >> a[i];
    for (int i=0; i<5; i++)
      cin >> b[i];

    bool valid = true;
    for (int i=0; i<5; i++)
      if (a[i] == b[i])
        valid = false;

    if (not valid)
      cout << "N\n";
    else
      cout << "Y\n";
  }

  return 0;
}
