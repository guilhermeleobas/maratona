/*
Problema - Dog and Gopher
http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1251
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

float dist (float x1, float y1, float x2, float y2){

	float result = 0;

	result = ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2));

	return result;
}

pair<float, float> solver (pair<float, float> dog, pair<float, float> gopher, vector<pair<float, float> > &holes){

	for (int i=0; i<holes.size(); i++){
		// cout << fixed << setprecision(5) << dist(dog.first, dog.second, holes[i].first, holes[i].second) << ' ' << 4* dist (gopher.first, gopher.second, holes[i].first, holes[i].second) << endl;
		if (dist (dog.first, dog.second, holes[i].first, holes[i].second) >= 4* dist (gopher.first, gopher.second, holes[i].first, holes[i].second)){
			return holes[i];
		}
		else if (gopher.first == holes[i].first && gopher.second == holes[i].second){
			return holes[i];
		}
	}

	return make_pair (INF, INF);
}


int main (){

	ios::sync_with_stdio(false);
	
	pair<float, float> gopher, dog, resp;
	vector<pair<float, float> > holes;
	float x, y;
	int n;

	while (true){
		cin >> n;

		if (!cin)
			break;

		holes.clear();
		holes.resize (n);

		cin >> gopher.first >> gopher.second >> dog.first >> dog.second;

		for (int i=0; i<n; i++){
			cin >> x >> y;
			holes[i] = make_pair (x, y);
		}

		resp = solver (dog, gopher, holes);

		if (resp.first != INF)
			cout << fixed << setprecision (3) << "The gopher can escape through the hole at (" << resp.first << ',' << resp.second << ").\n";
		else
			cout << "The gopher cannot escape.\n";
	}

	

	return 0;
}
