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

float euclidean_distance (int x1, int y1, int x2, int y2){

	return (float)sqrt ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main (){

	ios::sync_with_stdio(false);
	
	int x1, x2, y1, y2;

	cin >> x1 >> y1 >> x2 >> y2;

	cout << fixed << setprecision (4) << euclidean_distance (x1, y1, x2, y2) << endl;

	return 0;
}
