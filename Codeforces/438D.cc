#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<vector<int> > graph;

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f

class Segtree {
  private:
    int n; vector<short> st, lazy;

    inline int left(int i){ return i<<1; }
    inline int right(int i){ return (i<<1)+1; }

    short rmq(int p, int L, int R, int i, int j)
    {
      if(i > R || j < L) return -1;
      fix(p, L, R);
      if(i <= L && j >= R) return st[p];

      short r1 = rmq(left(p), L, (L+R)/2, i, j);
      short r2 = rmq(right(p), (L+R)/2+1, R, i, j);

      if(r1 == -1) return r2;
      if(r2 == -1) return r1;
      if(r1 >= r2) return r1;
      return r2;
    }

    void build()
    {
      for(unsigned i = 0; i < this->st.size(); i++)
        this->st[i] = this->lazy[i] = 0;
    }

    inline void fix(int p, int L, int R)
    {
      if(L < R)
      {
        lazy[left(p)] += lazy[p];
        lazy[right(p)] += lazy[p];
      }
      st[p] += lazy[p];
      lazy[p]=0;
    }

    void upd(int p, int L, int R, int i, int j)
    {
      if(i > R || j < L) return;
      if(i <= L && j >= R)
      {
        lazy[p]++;
        fix(p, L, R);
        return;
      }

      upd(left(p), L, (L+R)/2, i, j);
      upd(right(p), (L+R)/2+1, R, i, j);
      st[p] = max(st[left(p)], st[right(p)]);
    }

  public:
    Segtree(int _n) // Remember you can use shrink_to_fit if needed
    {
      this->n = _n;
      this->st.assign(2*_n+(_n/10), 0);
      this->lazy.assign(2*_n+(_n/10), 0);
      this->build();
    }

    short rmq(int i, int j)
    { return rmq(1, 0, this->n-1, i, j); }

    short rmq()
    { return rmq(1, 0, this->n-1, 0, this->n-1); }

    void sumOne(int i, int j)
    {
      if(i > j) swap(i, j);
      this->upd(1, 0, this->n-1, i+2000002, j+2000002);
    }
};


int main (){
  
  
  
  return 0;
}
