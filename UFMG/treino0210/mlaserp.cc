/*
Problema - Laser Phones
http://www.spoj.com/problems/MLASERP/
Use clang_cpp instead of g++
Guilherme Leobas
*/

/*
Direções - Directions;
  0
  3 * 1
    2
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>

using namespace std;

#define PI acos(-1)
#define cnt PI/180
#define INF 99999999

typedef pair<int, int> node;

typedef struct {
  pair<int, int> no;
  int cost;
  int direction;
} cell;

int graph[110][110];
int cost[110][110];
int n, m;

bool operator < (cell a, cell b){
  return a.cost < b.cost;
}

bool operator > (cell a, cell b){
  return a.cost > b.cost;
}

bool operator == (cell a, cell b){
  return a.cost == b.cost;
}

bool valid (int l, int c){
  if (l >= 0 && l < n && c >= 0 && c < m && graph[l][c] >= 0)
    return true;

  return false;
}

cell make_cell (int l, int c, int direction, int cost){
  cell celula;

  celula.no = make_pair (l, c);
  celula.direction = direction;
  celula.cost = cost;

  return celula;
}

void imprime (){
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      if (cost[i][j] == INF){
        cout << "I ";
      }
      else cout << cost[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl << endl;
}

void dijkstra (map<int, node> &mapa, node start){
  
  priority_queue<cell, vector<cell>, greater<cell> > pq;
  cell atual, next;
  node no;

  atual.no = start;
  atual.cost = 0;

  for (int i=0; i<4; i++){
    atual.direction = i;
    pq.push (atual);
  }

  cost[start.first][start.second] = 0;

  while (!pq.empty()){

    // imprime ();

    atual = pq.top();
    pq.pop();

    no = atual.no;

    // if (mapa[1] == no) break;

    // cout << no.first << ' ' << no.second << ' ' << graph[no.first][no.second] << endl;

    for (int d=-1; d <= 1; d+= 2){
      if (d < 0){
        if (valid (no.first+d, no.second) ) {
          // cout << "avaliou (0)\n";
          if (atual.direction != 0){
            if (cost[no.first+d][no.second] >= atual.cost + 1){
              cost[no.first+d][no.second] = atual.cost + 1;
              pq.push (make_cell (no.first+d, no.second, 0, cost[no.first+d][no.second]));
            }
          }
          else if (cost[no.first+d][no.second] >= atual.cost){
            cost[no.first+d][no.second] = atual.cost;
            pq.push (make_cell (no.first+d, no.second, 0, cost[no.first+d][no.second]));
          }
        }

        if (valid (no.first, no.second+d) ){
          // cout << "avaliou (3)\n";
          if (atual.direction != 3){
            if (cost[no.first][no.second+d] >= atual.cost + 1){
              cost[no.first][no.second+d] = atual.cost + 1;
              pq.push (make_cell (no.first, no.second+d, 3, cost[no.first][no.second+d]));
            }
          }
          else if (cost[no.first][no.second+d] >= atual.cost){
            cost[no.first][no.second+d] = atual.cost;
            pq.push (make_cell (no.first, no.second+d, 3, cost[no.first][no.second+d]));
          }
        }
      }
      else {
        // D > 0;

        if (valid (no.first+d, no.second) ){
          if (atual.direction != 2){
            // cout << "avaliou (2-a) ";
            if (cost[no.first+d][no.second] >= atual.cost + 1){
              // cout << "Update\n";
              cost[no.first+d][no.second] = atual.cost + 1;
              pq.push (make_cell (no.first+d, no.second, 2, cost[no.first+d][no.second]));
    
            }
          }
          else if (cost[no.first+d][no.second] >= atual.cost){
            // cout << "avaliou (2-b) Update\n";;
            cost[no.first+d][no.second] = atual.cost;
            pq.push (make_cell (no.first+d, no.second, 2, cost[no.first+d][no.second]));
          }
        }

        if (valid (no.first, no.second+d) ){
          if (atual.direction != 1){
            // cout << "avaliou (1-a) ";
            if (cost[no.first][no.second+d] >= atual.cost + 1){
              // cout << " Update";
              cost[no.first][no.second+d] = atual.cost + 1;
              pq.push (make_cell (no.first, no.second+d, 1, cost[no.first][no.second+d]));
            }
            // cout << endl;
          }
          else if (cost[no.first][no.second+d] >= atual.cost){
            // cout << "avaliou (1-b) e update\n";
            cost[no.first][no.second+d] = atual.cost;
            pq.push (make_cell (no.first, no.second+d, 1, cost[no.first][no.second+d]));
          }
        }

      }
    }

  }
}


int main (){

  ios::sync_with_stdio(false);

  cin >> m >> n;
  map<int, node> mapa;

  char c;

  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      cin >> c;

      cost[i][j] = INF;

      if (c == '.'){
        graph[i][j] = 0;
      }
      else if (c == '*'){
        graph[i][j] = -1;
      }
      else if (c == 'c' || c == 'C'){
        graph[i][j] = 2;
        mapa[mapa.size()] = make_pair (i, j);
      }
    }
  }

  dijkstra (mapa, mapa[0]);

  cout << cost[mapa[1].first][mapa[1].second] << endl;

  return 0;
}

