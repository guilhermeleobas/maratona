#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector<vector<int> > graph;

#define INF 999999

void print (graph &g){
	
	for (int i=0; i<150; i++){
		cout << i << ": ";
		for (int j=0; j<g[i].size(); j++){
			cout << g[i][j] << ' ';
		}
		cout << endl;
	}
}

int bfs (graph &g){
	
	queue<pair<int, int> > q;
	pair<int, int> node;
	int next;
	vector<int> cost (1200, INF);
	vector<int> visited (1200, 0);

	node.first = 100;
	node.second = 0;

	visited[100] = 1;
	cost[100] = 0;

	q.push (node);

	while (!q.empty()){
		
		node = q.front();
		q.pop();

		visited[node.first] = 1;

		//cout << "visitou: " << node.first << ' ' << node.second << endl;

		if (node.first == 0) return cost[node.first];

		for (int i=0; i<g[node.first].size(); i++){
			next = g[node.first][i];

			//cout << "v: " << next << endl;

			if (visited[next]) continue;

			if (cost[next] > node.second+1){
				cost[next] = node.second+1;
				q.push (make_pair (next, cost[next]));
			}
		}
	}

	return cost[0];
}

int main (){
	
	int n;

	while (true){
		cin >> n;
		if (not n) break;

		vector<int> att (n);
		vector<int> def (n);
		graph g (1500);

		for (int i=0; i<n; i++)
			cin >> att[i];

		for (int i=0; i<n; i++)
			cin >> def[i];

		for (int i=0; i<=1300; i++){
			for (int j=0; j<n; j++){
				if (i - att[j] < 0) continue;

				if (i - att[j] == 0)
					g[i].push_back (0);
				
				g[i].push_back (i-att[j]+def[j]);
			}
		}
		
		//print (g);
		int ans = bfs (g);

		if (ans == INF)
			cout << "cavaleiro morreu\n";
		else
			cout << ans << endl;
	}

	return 0;
}
