/*
Problema - Monitorando a Amazônia
http://br.spoj.com/problems/MONAMAZ/
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
#include <iomanip>

using namespace std;

#define PI acos(-1)
#define cnt PI/180
#define INF 99999999
typedef vector<vector<pair<int, int> > > graph;
double dist[1010][1010];

struct point {

	int x, y, i;

	point (){
		x = INF;
		y = INF;
	}

	point (int _x, int _y, int _i){
		x = _x;
		y = _y;
		i = _i;
	}
};

int calc_dist (point a, point b){
	return ( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

bool bfs (vector<point> &P){

	queue<int> q;
	vector<int> visited (P.size(), 0);
	int atual, next1, next2, n = P.size();
	double dist1, dist2;

	q.push (0);
	visited[0] = 1;

	while (!q.empty()){

		atual = q.front();
		q.pop();

		next1 = -1;
		dist1 = INF;
		next2 = -1;
		dist2 = INF;

		for (int i=0; i<n; i++){

			if (i == atual)
				continue;

			// cout << i << ' ' << dist[atual][i] << endl;

			if (dist1 > dist[atual][i]){
				dist1 = dist[atual][i];
				next1 = i;
			}
			else if (dist1 == dist[atual][i]){
				if (P[next1].x > P[i].x){
					next1 = i;
				}
				else if (P[next1].x == P[i].x){
					if (P[next1].y > P[i].y){
						next1 = i;
					}
				}
			}
		}

		for (int i=0; i<n; i++){

			if (i == next1 || i == atual)
				continue;

			if (dist2 > dist[atual][i]){
				dist2 = dist[atual][i];
				next2 = i;
			}
			else if (dist2 == dist[atual][i]){
				if (P[next2].x > P[i].x){
					next2 = i;
				}
				else if (P[next2].x == P[i].x){
					if (P[next2].y > P[i].y){
						next2 = i;
					}
				}
			}
		}

		if (next1 != -1 && !visited[next1]){
			q.push (next1);
			visited[next1] = 1;
		}

		if (next2 != -1 && !visited[next2]){
			q.push (next2);
			visited[next2] = 1;
		}
	}

	for (int i=0; i<visited.size(); i++){
		if (!visited[i])
			return false;
	}

	return true;
}


int main (){

	ios::sync_with_stdio(false);
	
	int n, x, y;
	vector<point> P;


	while (true){
		cin >> n;

		if (!n)
			break;

		P.clear();
		P.resize (n);

		for (int i=0; i<n; i++){
			cin >> x >> y;
			P[i] = point (x, y, i);
		}

		for (int i=0; i<n; i++){
			for (int j=i+1; j<n; j++){
				dist[i][j] = calc_dist (P[i], P[j]);
				dist[j][i] = dist[i][j];
			}
		}

		if (bfs (P)){
			cout << "All stations are reachable.\n";
		}
		else {
			cout << "There are stations that are unreachable.\n";
		}
	}
	
	

	

	return 0;
}
