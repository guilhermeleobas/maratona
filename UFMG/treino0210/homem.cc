#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define segtree_size 300010

struct pedra {
  int homem, elefante, rato;
  bool valid;
  pedra (){
    homem = 0;
    elefante = 0;
    rato = 0;
    valid = true;
  }

  void merge (const pedra& l, const pedra& r){
    homem = l.homem + r.homem;
    elefante = l.elefante + r.elefante;
    rato = l.rato + r.rato;
  }

  void update (const pedra& parent){
    homem = parent.homem;
    elefante = parent.elefante;
    rato = parent.rato;
  }

  void swap (){
    int aux = rato;
    rato = elefante;
    elefante = homem;
    homem = aux;
  }

  void print(){
    cout << homem << ' ' << elefante << ' ' << rato << endl;
  }

};

template <typename T>
class Segtree {
  private:
    vector<T> segtree;
    vector<bool> lazy;
    int __size;

    void inicializa (const vector<T>& vetor, int node, int l, int r){

      if (l > r) return;

      if (l == r){
        segtree[node] = vetor[r];
      }
      else {
        inicializa (vetor, 2*node+1, l, (l+r)/2);
        inicializa (vetor, 2*node+2, (l+r)/2+1, r);

        segtree[node].merge (segtree[2*node+1], segtree[2*node+2]);
      }
    }

    // default values
    // update (0, 0, size-1, pos);
    // size-1 => size of the array "vetor"
    // pos => leaf you want to change
    void update (const T& t, int node, int l, int r, const int pos){

      if (l > r || l > pos || r < pos)
        return;

      if (l == pos && r == pos){
        segtree[node] = t;
        return;
      }

      update (t, 2*node+1, l, (l+r)/2, pos);
      update (t, 2*node+2, (l+r)/2+1, r, pos);

      // Condição: pai = max (fllho1, filho2);
      segtree[node].merge (segtree[2*node+1], segtree[2*node+2]);
    }

    T range_update (int node, int left, int right, const int lo, const int hi){


      if (lazy[node] == true){
        // this node needs to be updated
        // cout << "no " << left << '-' << right << " precisa ser atualizado" << endl;

        lazy[node] = false; // reset it

        segtree[node].swap(); // update it
        // cout << "no " << left  << '-' << right << " mudou de valor para ";
        // segtree[node].print();

        if (left != right){
          lazy[2*node + 1] = true;
          lazy[2*node + 2] = true;
        }
      }

      // current segment not in range
      if (left > right || left > hi || right < lo)
        return pedra();

      // segment is fully within range
      if (left >= lo and right <= hi){
        // cout << "chegou aqui com left = " << left << "    right = " << right << endl;
        segtree[node].swap(); // update it
        if (left != right){
          lazy[2*node+1] = true; // lazy
          lazy[2*node+2] = true; // lazy
        }
        return segtree[node];
      }

      range_update (2*node+1, left, (left+right)/2, lo, hi);
      range_update (2*node+2, (left+right)/2+1, right, lo, hi);

      segtree[node].merge (segtree[2*node+1], segtree[2*node+2]);

      return segtree[node];

    }

    // default value
    // query (0, 0, size-1, i, j)
    // size-1 => refers to the size of the array vetor
    // [l, r] => query pointers
    // [i, j] => desirable interval pointers
    T __query (int node, int left, int right, int lo, int hi){

      // cout << "node: " << node << " left: " << left << " right: " << right << endl;

      if (lazy[node]){
        segtree[node].swap();
        if (left != right){
          lazy[2*node+1] = true;
          lazy[2*node+2] = true;
        }

        lazy[node] = false;
      }

      if (left >= lo and right <= hi)
        return segtree[node];

      T p1, p2;

      int mid = (left + right)/2;

      if (lo > mid)
        return __query (2*node+2, mid+1, right, lo, hi);
      if (hi <= mid)
        return __query (2*node+1, left, mid, lo, hi);

      p1 = __query (2*node+2, mid+1, right, lo, hi);
      p2 = __query (2*node+1, left, mid, lo, hi);

      T ret;
      ret.merge (p1, p2);
      return ret;
    }

  public:

    Segtree (): segtree (segtree_size), __size (0), lazy(segtree_size)
    {}

    void init (const vector<T>& vetor, int l, int r){
      __size = vetor.size();
      inicializa (vetor, 0, l, r);
    }

    void update (const T& t, const int pos){
      update (t, 0, 0, __size-1, pos);
    }

    T query (const int i, const int j){
      return range_update (0, 0, __size-1, i, j);
    }

    void range_update (const int i, const int j){
      range_update (0, 0, __size-1, i, j);
    }

    const int size (void) const{
      return __size;
    }

    void print (){
      for (int i=0; i<9; i++){
        cout << "i: " << i << " - ";
        segtree[i].print();
      }
      cout << endl;
      for (int i=0; i<9; i++){
        cout << lazy[i] << ' ';
      }
      cout << endl;
    }

};

int main (){

  while (true){
    int n, m;
    cin >> n >> m;
    if (not cin) break;

    Segtree<pedra> segtree;
    pedra p;
    p.homem = 1;
    vector<pedra> v (n, p);

    segtree.init (v, 0, n-1);


    for (int i=0; i<m; i++){
      char c;
      int a, b;
      cin >> c >> a >> b;
      if (c == 'C'){
        // cout << "Consulta " << a-1 << ' ' << b-1 << endl;
        // segtree.print();
        pedra aux = segtree.query (a-1, b-1);
        cout << aux.homem << ' ' << aux.elefante << ' ' << aux.rato << endl;
      }
      else {
        // cout << "range update " << a-1 << ' ' << b-1 << endl;
        segtree.range_update (a-1, b-1);
        // segtree.print();
        // for (int i=a; i<=b; i++){
        //   pedra aux = segtree.query (i-1, i-1);
        //   int rato = aux.rato;
        //   aux.rato = aux.elefante;
        //   aux.elefante = aux.homem;
        //   aux.homem = rato;
        //   segtree.update (aux, i-1);
        // }
      }
      // cout << "-----------" << endl;
    }

    cout << endl;

  }


  return 0;
}
