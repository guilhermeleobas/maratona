#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool check_line (int c[9]){
  for (int i=0; i<9; i++){
    for (int j=i+1; j<9; j++){
      if (c[i] == c[j])
        return false;
    }
  }
  
  return true;
}

bool check_column (int v[9][9], int c){
  for (int i=0; i<9; i++){
    for (int j=i+1; j<9; j++){
      if (v[i][c] == v[j][c])
        return false;
    }
  }
  
  return true;
}

bool check_square (int v[9][9], int x, int y){
  vector<int> aux;
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
      aux.push_back (v[x*3 + i][y*3 + j]); 
    }
  }
  
  for (int i=0; i<aux.size(); i++){
    for (int j=i+1; j<aux.size(); j++){
      if (aux[i] == aux[j])
        return false;
    }
  }
  
  return true;
}

bool check (int v[9][9]){
  
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
      bool status = check_square (v, i, j);
      if (not status) return false;
    }
  }
  
  for (int j=0; j<9; j++){
    bool status = check_column (v, j);
    if (not status) return false;
  }
  
  for (int i=0; i<9; i++){
    bool status = check_line (v[i]);
    if (not status) return false;
  }
  
  return true;
}


int main (){

  int t;
  cin >> t;
  
  int instance = 1;
  while (t--){
    int v[9][9];
    
    for (int i=0; i<9; i++)
      for (int j=0; j<9; j++)
        cin >> v[i][j];
    
    cout << "Instancia " << instance++ << endl;
    bool status = check (v);
    if (not status)
      cout << "NAO" << endl;
    else
      cout << "SIM" << endl;
    
    cout << endl;
  }
  
  return 0;
}
