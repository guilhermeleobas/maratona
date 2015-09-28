#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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

        segtree[node] = segtree[2*node+1] * segtree[2*node+2];
    }

}

// default values
// update (0, 0, size-1, pos);
// size-1 => size of the array "vetor"
// pos => position in the array "vetor" that you previously did the change
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
    segtree[node] = segtree[2*node+1] * segtree[2*node+2];
}

// default value
// query (0, 0, size-1, i, j)
// size-1 => reefers to the size of the array vetor
// [i, j] => query pointers
int query (int node, int l, int r, int i, int j){

    int p1, p2;

    //size overflow;
    if (l > r || l > j || r < i){
      return 1000000007;;
    }

    //Intervalo incluido
    if (l >= i && r <= j)
        return segtree[node];

    //
    p1 = query (2*node+1, l, (l+r)/2, i, j); 
    p2 = query (2*node+2, (l+r)/2+1, r, i, j);

    // Condição: pai = max (fllho1, filho2);
    if (p1 == 1000000007)
      return p2;
    if (p2 == 1000000007)
      return p1;
        
    return p1*p2;
}

void print (){
  
  cout << "----\n";
  for (int i=0; i<10; i++){
    cout << segtree[i] << ' ';
  }
  
  cout << endl;
}
int main (){
  
  ios::sync_with_stdio(false);
  while (true){
    int n, k;
    cin >> n >> k;
    
    if (not cin) break;
    
    for (int i=0; i<n; i++){
      cin >> vetor[i];
      if (vetor[i] > 0)
        vetor[i] = 1;
      else if (vetor[i] < 0)
        vetor[i] = -1;
      else
        vetor[i] = 0;
    }
    
    inicializa (0, 0, n-1);
    
    for (int i=0; i<k; i++){
      
      char c;
      cin >> c;
      
      if (c == 'C'){
        int I, V;
        cin >> I >> V;
        if (V > 0)
          vetor[I-1] = 1;
        else if (V < 0)
          vetor[I-1] = -1;
        else
          vetor[I-1] = 0;
        update (0, 0, n-1, I-1);
      }
      else {
        int I, J;
        cin >> I >> J;
        int ans = query (0, 0, n-1, I-1, J-1);
        if (ans == 0)
          cout << '0';
        else if (ans < 0)
          cout << '-';
        else
          cout << '+';
      }
    }
    cout << endl;
  }
  return 0;
}
