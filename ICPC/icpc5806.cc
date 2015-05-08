#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

typedef struct point {
  double x, y;

  point (){
    x = 0;
    y = 0;
  }

  point (double x, float y){
    this->x = x;
    this->y = y;
  }

  point (int x, int y){
    this->x = double(x);
    this->y = double(y);
  }
} point;

typedef struct reta {
  double angular, independente;
  
  reta (point s, point r){
    angular = (double)(r.y - s.y)/(r.x - s.x);
    independente = r.y - angular*r.x;
  } 
  reta (double angular, float independente){
    this->angular = angular;
    this->independente = independente;
  }

  double gety (float x){
    return x*angular + independente;
  }
} reta;

point pmedio (point p, point q){
  point medio;
  medio.x = (p.x + q.x)/2;
  medio.y = (p.y + q.y)/2;

  return medio;
}

point intercept (reta r, reta s){
  point p;
  p.x = (r.independente - s.independente)/(s.angular - r.angular);
  p.y = r.gety (p.x);
  return p;
}

double area_T (point p1, point p2, point p3){
  return fabs((p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y)+ p3.x*(p1.y-p2.y))/2.0)/160;
}

double dist (point r, point s){
  return sqrt((r.y-s.y)*(r.y-s.y) + (r.x-s.x)*(r.x-s.x));
}

int main (){
  
  int p;
  cin >> p;

  while (p--){
    int id;
    cin >> id;
    point a, b, c, d;

    a.x = 0;
    a.y = 0;
    cin >> b.x;
    b.y = 0;
    cin >> c.x >> c.y >> d.x >> d.y;

    point alinha = pmedio (b, c);
    point blinha = pmedio (c, d);
    point clinha = pmedio (d, a);
    point dlinha = pmedio (a, b);

    reta ra (a, alinha);
    reta rb (b, blinha);
    reta rc (c, clinha);
    reta rd (d, dlinha);

    point rab = intercept (ra, rb);
    point rbc = intercept (rb, rc);
    point rcd = intercept (rc, rd);
    point rda = intercept (rd, ra);

    double ans = area_T (rda, rbc, rcd) + area_T (rda, rbc, rab);
    double al = area_T (a, b, rab);
    double bob = area_T (b, c, rbc);
    double chas = area_T (c, d, rcd);
    double dave = area_T (d, a, rda);
    double per = dist (rda, rab) + dist(rab, rbc) + dist(rbc, rcd) + dist(rcd, rda);
    per *= 16.5;
    cout << fixed << setprecision(3) << id << ' ' << al << ' ' << bob << ' ' << chas << ' ' << dave << ' ' << ans << ' ' << setprecision(0) << ceil(per) << endl;


  }
  

  return 0;
}
