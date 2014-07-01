/*
Problema - Elevador
http://br.spoj.com/problems/ELEVADOR/
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

int largura, comprimento;

bool cabe (int r1, int r2){
	if (comprimento >= 2*r1) return true;

	return false;
}

bool go (int r1, int r2){
	if (comprimento >= 2*r1 + 2*r2) return true;

	if (largura >= 2*r1 + 2*r2) return true;

	if ( ((largura-r1-r2)*(largura-r1-r2) + (comprimento-r1-r2)*(comprimento-r1-r2)) >= (r1+r2)*(r1+r2) ) return true;

	return false;
}

int main (){

	ios::sync_with_stdio(false);
	
	int r1, r2;
	float R;

	while (true){
		cin >> largura >> comprimento >> r1 >> r2;

		if (largura == 0 && comprimento == 0 && r1 == 0 && r2 == 0) break;

		if (largura < comprimento) swap (largura, comprimento);

		if (r1 < r2) swap (r1, r2);

		if (cabe (r1, r2) && go (r1, r2)){
			cout << "S\n";
		}
		else {
			cout << "N\n";
		}
	}	

	

	return 0;
}