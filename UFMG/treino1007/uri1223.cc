// [SPOILER]
// Não se esqueça de calcular a distancia entre a ultima aleta e a parede
// do not forget to calc the distance between the last flap and the wall

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
#define INF 1e10
const double EPS = 1e-10;
typedef vector<vector<pair<int, int> > > graph;
 
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

double calc_distance (point wall_p, point wall_q, point seg_p, point seg_q, point r){
  return min (seg_distance(wall_p, wall_q, r), seg_distance (seg_p, seg_q, r));
}

double solver (point leftwall_i, point leftwall_f, point rightwall_i, point rightwall_f, const vector<pair<point, point> > &v){
  
  double m = 0x3f3f3f3f;
  for (int i=0; i<v.size()-1; i++){
    double aux;
    if (i % 2 == 0)
      aux = calc_distance (rightwall_i, rightwall_f, v[i+1].first, v[i+1].second, v[i].second);
    else
      aux = calc_distance (leftwall_i, leftwall_f, v[i+1].first, v[i+1].second, v[i].second);

    m = min (m, aux);
  }

  if (v.size()-1 % 2 == 0){
    m = min (m, seg_distance (rightwall_i, rightwall_f, v.back().second));
  }
  else {
    m = min (m, seg_distance (leftwall_i, leftwall_f, v.back().second));
  }
  
  return m;
}

int main (){
  
  while (true){
    int n;
    cin >> n;

    if (not cin) break;
    
    int l, h;
    cin >> l >> h;
    point leftwall_i (0, 0), leftwall_f (0, h), rightwall_i(l, 0), rightwall_f(l, h);
    
    vector<pair<point, point> > v;
    for (int i=1; i<=n; i++){
      int x_inicio, y_inicio, x_fim, y_fim;
      if (i % 2 == 0)
        x_inicio = l;
      else
        x_inicio = 0;
      cin >> y_inicio >> x_fim >> y_fim;

      v.push_back (make_pair (point(x_inicio, y_inicio), point(x_fim, y_fim) ));
    }

    cout << fixed << setprecision (2) << solver (leftwall_i, leftwall_f, rightwall_i, rightwall_f, v) << endl;
  }
  return 0;
}
