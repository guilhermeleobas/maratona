/*
Problema - Diagrama de voronoi
http://br.spoj.com/problems/DVORONOI/
Guilherme Leobas
*/

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

using namespace std;

#define PI acos(-1)
#define cnt PI/180
#define INF 99999999
typedef vector<vector<pair<int, int> > > graph;

void imprime (double vetor[4][3]){
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			printf ("%g ", vetor[i][j]);
		}
		printf ("\n");
	}
	printf ("\n");
}

double determinante (double a[4][3]){

	double p1, p2;

	p1 = a[0][0]*a[1][1]*a[2][2] + a[1][0]*a[2][1]*a[0][2] + a[2][0]*a[0][1]*a[1][2];

	p2 = a[2][0]*a[1][1]*a[0][2] + a[1][0]*a[0][1]*a[2][2] + a[0][0]*a[2][1]*a[1][2];

	return p1-p2;
}

int main (){

	// ios::sync_with_stdio(false);
	
	double vetor[4][3];
	double a[3];
	double aux[3];
	double result;

	int t, num;

	cin >> t;

	while (t-- > 0){

		for (int i=0; i<3; i++){
			scanf ("%lf", &a[i]);
		}

		for (int i=0; i<3; i++){
			for (int j=0; j<3; j++){
				scanf ("%lf", &aux[j]);
				vetor[i][j] = aux[j]-a[j];
			}
		}

		// imprime (vetor);
		result = determinante (vetor);

		printf ("%.6lf\n", abs(result)/6);

	}

	

	return 0;
}