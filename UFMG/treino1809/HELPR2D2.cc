#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 100010

int segtree[300010];
int vetor[100100];

void inicializa (int node, int l, int r){

  if (l > r) return;

  if (l == r){
    segtree[node] = vetor[r];
  }
  else {
    inicializa (2*node+1, l, (l+r)/2);
    inicializa (2*node+2, (l+r)/2+1, r);

    segtree[node] = segtree[2*node+1];
  }

}

// default values
// update (0, 0, size-1, pos);
// size-1 => size of the array "vetor"
// pos => position in the array "vetor" that you previously changed
// 0 0
void update (int node, int l, int r, int pos){

  if (l > r || l > pos || r < pos)
    return;

  if (l == pos && r == pos){
    segtree[node] = vetor[pos];
    return;
  }

  update (2*node+1, l, (l+r)/2, pos);
  update (2*node+2, (l+r)/2+1, r, pos);

  // Condição: pai = max (fllho1, filho2);
  segtree[node] = max (segtree[2*node+1], segtree[2*node+2]);
}

// default value
// query (0, 0, size-1, i, j)
// size-1 => refers to the size of the array vetor
// [i, j] => query pointers
int query (int node, int l, int r, int i, int j, int dvalue){

  int p1, p2;

  //size overflow;
  if (l > r || l > j || r < i){
    return -1;
  }

  // nó folha
  if (l == r){
    segtree[node] -= dvalue;
    return l;
  }

  p1 = segtree[2*node+1];
  p2 = segtree[2*node+2];
  
  if (p1 >= dvalue and p1 != -1){
    return query (2*node+1, l, (l+r)/2, i, j, dvalue);
  }
  else if (p2 != -1){
    return query (2*node+2, (l+r)/2+1, r, i, j, dvalue);
  }
  else {
    return -1;
  }
}

int main (){

  int t;
  cin >> t;

  while (t--){
    
    for (int i=0; i<MAX; i++)
      vetor[i] = 0;
    for (int i=0; i<300000; i++)
      segtree[i] = 0;
    

    int k;
    cin >> k;

    for (int i=0; i<MAX; i++)
      vetor[i] = k;
    inicializa (0, 0, MAX);

    int n;
    cin >> n;

    string aux;

    for (int i=0; i<n; i++){
      string aux;
      cin >> aux;
      if (aux == "b"){
        int r, v;
        cin >> r >> v;
        for (int j=0; j<r; j++){
          int p = query (0, 0, MAX, 0, MAX, v);
          vetor[p] -= v;
          update (0, 0, MAX, p);
        }
        i += r-1;
      }
      else {
        int v = stoi (aux);
        int p = query (0, 0, MAX, 0, MAX, v);
        vetor[p] -= v;
        update (0, 0, MAX, p);
      }
    }

    int sum = 0;
    int used = 0;
    for (int i=0; i<MAX; i++){
      if (vetor[i] < k){
        sum += vetor[i];
        used ++;
      }
    }

    cout << used << ' ' << sum << endl;

  }

  return 0;
}
