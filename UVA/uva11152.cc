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
typedef vector<vector<pair<int, int> > > graph;

int main (){

	ios::sync_with_stdio(false);
	
	int a, b, c;
	double c_menor, c_maior, triangulo, s;

	while (true){
		cin >> a >> b >> c;
		if (!cin) break;

		s = (double)(a+b+c)*0.5;

		triangulo = sqrt(s*(s-a)*(s-b)*(s-c));

		c_menor = pow ((double)triangulo/s, 2)*PI;

		c_maior = pow ((double)(a*b*c)/(4*triangulo), 2)*PI;

		c_maior -= triangulo;
		triangulo -= c_menor;

		cout << setprecision(4) << fixed << c_maior << ' ' << triangulo << ' ' << c_menor << endl;
	}
	

	return 0;
}