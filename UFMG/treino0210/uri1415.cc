#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

char m[101][101];

void dfs (int r, int c){
  stack<pair<int, int> > s;
  int visited[101][101];
  memset (visited, 0, sizeof(int)*101*101);
  
  for (int i=0; i<r; i++){
    for (int j=0; j<c; j++){
      if (m[i][j] == '('){
        s.push (make_pair (i, j));
      }
    }
  }
  
  while (not s.empty()){
    pair<int, int> atual = s.top();
    s.pop();
    
    visited[atual.first][atual.second] = 1;
    
    for (int i=-1; i<=1; i++){
      for (int j=-1; j<=1; j++){
        if (i == -1 and j == -1) continue;
        if (i == 1 and j == 1) continue;
        if (atual.first + i < 0 or atual.first + i >= r) continue;
        if (atual.second + j < 0 or atual.second + j >= c) continue;
        
        int ni = atual.first + i;
        int nj = atual.second + j;
        
        if (m[atual.first][atual.second] != 'B' and visited[ni][nj])
          continue;
        if (m[atual.first][atual.second] == 'B'){
          if (m[ni][nj] != '.' and m[ni][nj] != 'B'){
            m[ni][nj] = 'B';
            s.push (make_pair (ni, nj));
          }
        }  
        else {
          if (m[ni][nj] == '*'){
            if (m[atual.first][atual.second] == '(')
              m[ni][nj] = ')';
            else if (m[atual.first][atual.second] == ')')
              m[ni][nj] = '(';
            s.push (make_pair (ni, nj));
          }
          else if ( (m[ni][nj] == '(' or m[ni][nj] == ')') and (m[ni][nj] == m[atual.first][atual.second]) ){
            m[ni][nj] = 'B';
            s.push (make_pair (ni, nj));
          }
        }
        
      }
    }
  }
}

int main (){
  
  bool bn = false;

  while (true){
    int r, c;
    cin >> r >> c;
    if (r==0 and c==0)break;
    cout << endl;
    memset (m, '.', 100*100*sizeof(char));
    
    for (int i=0; i<r; i++){
      for (int j=0; j<c; j++){
        cin >> m[i][j];
        if (m[i][j] == 'I')
          m[i][j] = '(';
      }
    }
    
    dfs (r, c);
    
    for (int i=0; i<r; i++){
      for (int j=0; j<c; j++){
        if (m[i][j] == '*') cout << 'F';
        else cout << m[i][j];
      }
      cout << endl;
    }
    
  }
  
  return 0;
}
