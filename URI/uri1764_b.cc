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
#define INF 0x3f3f3f3f
const double EPS = 1e-10;
typedef vector<vector<pair<double, int> > > graph;
 
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
 
struct point {
    double x, y;
 
    point () {
        x = INF, y = INF;
    }
 
    point (double _x, double _y){
        x = _x, y = _y;
    }
 
    point operator + (point q){
        return point (x + q.x, y + q.y);
    }
 
    point operator - (point q){
        return point (x - q.x, y - q.y);
    }
 
    point operator + (double T){
        return point (x + T, y + T);
    }
 
    point operator - (double T){
        return point (x - T, y - T);
    }
 
    point operator * (double T){
        return point (x*T, y*T);
    }
 
    point operator / (double T){
        return point (x/T, y/T);
    }
 
    double operator % (point q){
        return (x*q.y - y*q.x);
    }
 
    double operator * (point q) {
        return (x*q.x + y*q.y);
    }
 
    int cmp(point q) const {
        if (int t = ::cmp(x, q.x)) return t;
        return ::cmp(y, q.y);
    }
 
    bool operator ==(point q) const { return cmp(q) == 0; }
    bool operator !=(point q) const { return cmp(q) != 0; }
    bool operator < (point q) const { return cmp(q) < 0; }
};
 
typedef struct point vetor;
 
double norma (vetor v){
    return sqrt( (v.x*v.x) + (v.y*v.y) );
}
 
vetor prod_vetorial (vetor a, vetor b){
    vetor r;
 
    r.x = a.x * b.y;
    r.y = - (b.x * a.y);
 
    return r;
}
 
double coef_angular (point p, point q){
    return ( (q.y-p.y) / (q.x-p.x) );
}
 
double prod_escalar (vetor a, vetor b){
    return (a.x*b.x + a.y*b.y);
}
 
// Calcula a distancia euclidiana de pointo a ponto.
double dist_point (point a, point b){
    double result = 0;
 
    result = ((a.x-b.x)*(a.x-b.x)) + ((a.y-b.y)*(a.y-b.y));
 
    return sqrt(result);
}
 
struct reta {
    double m, n;

    reta (){
        m = 0;
        n = 0;
    }

    reta (point p, point q){
        m = (q.y - p.y)/(q.x - p.x);
        n = p.y - m*p.x;
    }


};

double dist_ponto_reta (reta r, point p){
    return abs((r.m*p.x - p.y + r.n))/(sqrt(r.m*r.m + 1));
}
 
// Calcula a distancia do ponto r ao segmento pq;
double seg_distance(point p, point q, point r) {
    point A = r - q, B = r - p, C = q - p;
    double a = A * A, b = B * B, c = C * C;
     
    if (cmp(b, a + c) >= 0) return sqrt(a);
    else if (cmp(a, b + c) >= 0) return sqrt(b);
    else return fabs(A % B) / sqrt(c);
}
 
// Retorna a area de um triangulo de lados {P1, P2, P3}
double area_T (point p1, point p2, point p3){
    return fabs((p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y)+ p3.x*(p1.y-p2.y))/2.0);
}
 
// Define se o ponto P está dentro do Triangulo de lados {P1, P2, P3}
bool inside_triangle (point P, point P1, point P2, point P3){
 
    double A = area_T (P1, P2, P3);
    double A2 = area_T (P, P2, P3);
    double A3 = area_T (P1, P, P3);
    double A4 = area_T (P1, P2, P);
 
    return (fabs(A - (A2 + A3 + A4)) <= EPS);
}
 
// Decide se o ponto P está dentro da circunferencia de centro (Center) e raio (raio);
bool inside_circle (point P, point center, double raio){
 
    if (dist_point (center, P) <= (double)raio)
        return true;
    else
        return false;
 
}

/*
    == 0 => colineares
    < 0  => anti-horario
    > 0  => horario
*/
int orientation (point p, point q, point r){
 
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    return val;
}

#define MAX 500+10
int parent[MAX];
int ranq[MAX];

void build_parent(int n){
  for (int i=0; i<=n; i++){
    parent[i] = i;
    ranq[i] = 1;
  }
}

int Find(int u){
  return u == parent[u] ? u : Find(parent[u]);
}

void Union (int u, int v){
  if (ranq[u] > ranq[v]){
    parent[Find(v)] = Find(u);
  }
  else{
    parent[Find(u)] = Find(v);
  }
  ranq[u] = ranq[v] = ranq[u] + ranq[v];
}

double kruskal (vector<pair<double, pair<int, int>>> &g, int n){
  build_parent(n);

  double total = 0.0;

  for (auto p : g){
    int u = p.second.first;
    int v = p.second.second;
    double cost = p.first;
  
    if (Find(u) != Find(v)){
      total += cost;
      Union (u, v);
    }
  }

  return total/100.0;
}


int prim(graph &g, int n){
  set<pair<int, int>> s;
  vector<bool> visited(n, false);
  vector<double> dist (n, INF);
  
  dist[0] = 0.0;
  s.insert(make_pair(0.0, 0));
  
  int total = 0.0;
  
  while (!s.empty()){
    
    auto p = *s.begin();
    s.erase(s.begin());
    
    int u = p.second;
    // total += p.first; //cost;
    
    visited[u] = true;
    
    for (auto it : g[u]){
      int v = it.second;
      int cost = it.first;
      if (!visited[v] && cost <= dist[v]){
        if (dist[v] != INF)
          total -= dist[v];
        total += cost;
        dist[v] = cost;
        s.insert(make_pair (dist[v], v));
      }
    }
    
  }
  
  return total;
}

int main (){
  
  cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

  while (true){
    int n, m;
    cin >> n >> m;
    
    if (n == 0 and m == 0) break;
    
    graph g (n);
    
    for (int i=0; i<m; i++){
      int u, v, cost;
      cin >> u >> v >> cost;
      
      g[u].push_back(make_pair (cost, v));
      g[v].push_back(make_pair (cost, u));
    }

    // cout << fixed << setprecision(2) << prim(g, n) << endl;
    cout << prim(g, n) << endl;
  }



  return 0;
}
