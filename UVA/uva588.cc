// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<pair<int, int> > > graph;

bool bellman_ford (graph g, int start){
	
	vector<int> distance (g.size(), 0x3f3f3f3f);
	distance[start] = 0;

	for (int i=0; i<g.size(); i++){
		for (int j=0; j<g.size(); j++){
			for (int k=0; k<g[j].size(); k++){
				int w = g[j][k].second;
				int y = g[j][k].first;
				int x = j;

				if (distance[y] > distance[x] + w){
					distance[y] = distance[x] + w;
				}
			}
		}
	}

	for (int i=0; i<g.size(); i++){
		for (int j=0; j<g[i].size(); j++){
			int x = i;
			int y = g[i][j].first;
			int w = g[i][j].second;
			if (distance[x] + w < distance[y]){
				return false;
			}
		}
	}

	return true;
}

int main (){

	int t;
	cin >> t;

	while (t--){
		int n, m;
		cin >> n >> m;
		
		graph g (n);

		for (int i=0; i<m; i++){
			int x, y, w;
			cin >> x >> y >> w;
			g[x].push_back (make_pair (y, w));
		}

		if (bellman_ford (g, 0))
			cout << "not possible\n";
		else
			cout << "possible\n";
	}

	return 0;
}
