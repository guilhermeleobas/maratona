/*Problem set: Trilhos/Rails:
http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=455
http://www.urionlinejudge.com.br/judge/pt/problems/view/1062

Guilherme Leobas;
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

stack<int> s;

void rails (int N){
	vector<int> v;
	int c, j;

	v.resize (N, 0);

	while (true){
		cin >> c;
		if (!c) break;

		v[0] = c;

		for (int i=1; i<N; i++){
			cin >> v[i];
		}

		j = 0;
		
		for (int i=0; i<N; i++){
			// if (s.size()) cout << "J: " << v[j] << "\ti: " << i << "\ts.top(): " << s.top() << endl;
			if (s.size() && v[j] == s.top()){
				s.pop();
				j++;
				i--;
			}
			else {
				s.push (i+1);
			}
		}

		while (s.size() && v[j] == s.top()){
			s.pop();
			j++;
		}

		if (!s.size()) cout << "Yes\n";
		else cout << "No\n";

		while (!s.empty()) s.pop();
	}
}

int main (){

	ios::sync_with_stdio(false);
	
	int N;

	while (true){
		cin >> N;
		if (N == 0) break;

		rails (N);

		while (!s.empty()) s.pop();

		cout << "\n";
	}

	

	return 0;
}
