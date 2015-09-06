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
const double EPS = 1e-5;
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

struct vetor {
  float x, y;
  
  vetor (){
    x = INF;
    y = INF;
  }
  
  vetor (float x, float y){
    this->x = x;
    this->y = y;
  }
  
  vetor (vetor p, vetor q){
    this->x = p.x - q.x;
    this->y = p.y - q.y;
  }
};

// typedef struct point vetor;
 
float norma (vetor v){
    return sqrt( (v.x*v.x) + (v.y*v.y) );
}
 
vetor prod_vetorial (vetor a, vetor b){
    vetor r;
 
    r.x = a.x * b.y;
    r.y = - (b.x * a.y);
 
    return r;
}
 
float coef_angular (point p, point q){
    return ( (q.y-p.y) / (q.x-p.x) );
}
 
float prod_escalar (vetor a, vetor b){
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

float calc_angle (vetor p, vetor q, vetor r){
  
  vetor pq (p, q);
  vetor pr (p, r);
  
  //cout << "p=" << p.x << ' ' << p.y << endl;
  //cout << "q=" << q.x << ' ' << q.y << endl;
  //cout << "r=" << r.x << ' ' << r.y << endl;
  //cout << "pq=" << pq.x << ' ' << pq.y << endl;
  //cout << "pr=" << pr.x << ' ' << pr.y << endl;
  //cout << pq.x << ' ' << pq.y << ' ' << pr.x << ' ' << pr.y << endl;
  //double p_esc = prod_escalar (pq, pr);
  //cout << p_esc << endl;
  
  float p_esc = prod_escalar (pq, pr);
  float npq = norma (pq);
  float npr = norma (pr);
  
  return acos ((p_esc)/(npq*npr)) * 180.0 / PI;
}

int main (){
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  
  for (int i=0; i<t; i++){
    float x1, x2, u1, u2, v1, v2, y1, y2;
    cin >> x1 >> y1 >> u1 >> v1 >> x2 >> y2 >> u2 >> v2;
    vetor hero (x1, y1);
    vetor pos1 (u1, v1);
    vetor heroine (x2, y2);
    vetor pos2 (u2, v2);
    
    float hero_ang = calc_angle (hero, pos1, heroine);
    float heroine_ang = calc_angle (heroine, pos2, hero);
    
    if (hero_ang > abs(360.0 - hero_ang))
      hero_ang = abs(360.0 - hero_ang);
    if (heroine_ang > abs(360.0 - heroine_ang))
      heroine_ang = abs(360.0 - heroine_ang);
    
    //cout << "hero=" << hero_ang << " heroine_ang=" << heroine_ang << endl;
    if (abs(hero_ang - heroine_ang) < EPS)
      cout << "0\n";
    else if (hero_ang < heroine_ang)
      cout << "Hero\n";
    else
      cout << "Heroine\n";
  }
  return 0;
}
