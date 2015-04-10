<<<<<<< HEAD
=======
// http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=37434

>>>>>>> afaf711a42034f9654dd16b143c95a891406e66d
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<pair<int, int> > > graph;

bool bellman_ford (graph g, vector<int> &distance, int start){
	
	distance[start] = 0;

	for (int i=0; i<g.size(); i++){
		for (int j=0; j<g.size(); j++){
			for (int k=0; k<g[j].size(); k++){
				int w = g[j][k].second;
				int y = g[j][k].first;
				int x = j;

        if (distance[x] == 0x3f3f3f3f) continue;

				if (distance[y] > distance[x] + w){
					distance[y] = distance[x] + w;

          if (i == g.size()-1){
            distance[y] = -0x3f3f3f3f;
          }
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
				// return false;
        distance[y] = 0x3f3f3f3f;
			}
		}
	}

	return true;
}

int main (){
	int set = 1;
	while (true){
		int n;
		cin >> n;
		if (not cin) break;

		vector<int> junction (n + 100);

		graph g (n);

		for (int i=0; i<n; i++)
			cin >> junction[i];
		
		int m;
		cin >> m;

		for (int i=0; i<m; i++){
			int x, y;
			cin >> x >> y;
			int w = junction[y-1] - junction[x-1];
			g[x-1].push_back (make_pair (y-1, w*w*w));
		}
		

		vector<int> distance (g.size() + 100, 0x3f3f3f3f);

		bellman_ford (g, distance, 0);

		int q;
		cin >> q;
		
		cout << "Set #" << set++ << endl;
		for (int i=0; i<q; i++){
			int dest;
			cin >> dest;
			if (distance[dest-1] < 3 or distance[dest-1] >= 0x3f3f3f3f)
				cout << "?\n";
			else
				cout << distance[dest-1] << endl;
		}
	}

	return 0;
}
