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
	long long x, y;

	point () {
		x = INF, y = INF;
	}

	void read(){
		cin >> this->x >> this->y;
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
};

point solve (point p, point q, point r){
	struct reta rs, pq;

	pq.m = (q.y - p.y)/(q.x - p.x);
	pq.n = p.y - pq.m*p.x;

	rs.m = -(q.x - p.x)/(q.y - p.y);
	rs.n = r.y - rs.m*r.x;

	double x = (rs.n - pq.n)/(pq.m - rs.m);
	double y = rs.m * x + rs.n;

	return (point (x, y));
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

int main(){

	point a, b, c;

	a.read();
	b.read();
	c.read();

	point ab = b-a;
	point ac = c-a;

	point pv = prod_vetorial (ac, ab);

	long long sign = (ac.x*ab.y) - (ab.x*ac.y);

	if (sign == 0)
		cout << "TOWARDS\n";
	else if (sign < 0)
		cout << "LEFT\n";
	else
		cout << "RIGHT\n";

	return 0;
}