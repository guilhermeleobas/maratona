/*

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

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs>rhs;}
};

int comp (int a, int b){
	return a>b;
}

int main (){

	ios::sync_with_stdio(false);

	set<int> normal;
	set<int, classcomp> invertido;

	int n, num;

	cin >> n;

	for (int i=0; i<n; i++){
		cin >> num;

		if (normal.find (num) == normal.end()) {
			normal.insert (num);
		}
		else {
			invertido.insert (num);
		}
	}

	set<int>::iterator maximo = normal.end();
	maximo--;

	if (*invertido.begin() == *maximo){
		invertido.erase (invertido.begin());
	}

	cout << normal.size() + invertido.size() << endl;

	for (set<int>::iterator it = normal.begin(); it != normal.end(); it++)
		cout << *it << ' ';
	for (set<int>::iterator it = invertido.begin(); it != invertido.end(); it++)
		cout << *it << ' ';
	cout << endl;
	

	

	return 0;
}
