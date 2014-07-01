#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>

using namespace std;
typedef vector<vector<int> > graph;

int find (vector<int> &def, int u){
	for (int i=0; i<def.size(); i++){
		if (def[i] == u) return i;
	}
}

void change (vector<int> &ages, vector<int> &def, int u, int v){
//	int a = find (def, u);
//	int b = find (def, v);
	
	//cout << "trocar: " << a+1 << "=" << u+1 << "\t" << b+1 << "=" << v+1 << endl;
//	swap (ages[a], ages[b]);
//	swap (def[a], def[b]);

	swap (ages[def[u]], ages[def[v]]);
	swap (def[u], def[v]);

}

void pvector (vector<int> &def){
	for (int i=0; i<def.size(); i++)
		cout << def[i]+1 << ' ';
	cout << endl;
}

int dfs (graph &g, vector<int> &age, vector<int> &def, int start){

	int n = g.size();
	stack<int> s;
	vector<int> visited (n, 0);
	int atual, next, ans = 99999999;
	
	s.push (start);
	visited[start] = 1;

	while (!s.empty()){
		
		atual = s.top();
		s.pop();

		for (int i=0; i<g[atual].size(); i++){
			next = g[atual][i];
			
			if (visited[next]) continue;
			ans = min (ans, age[next]);
			s.push (next);
			visited[next] = 1;
		}
	}

	return ans;
}

void print (graph &g){

	for (int i=0; i<g.size(); i++){
		cout << i+1 << ": ";
		for (int j=0; j<g[i].size(); j++){
			cout << g[i][j]+1 << ' ';
		}
		cout << endl;
	}
}

int main(){
	
	int n, m, I;
	graph g;
	vector<int> ages, def;

	while (true){
		cin >> n >> m >> I;

		if (!cin) break;
		
		g.clear();
		ages.clear();
		def.clear();

		ages.resize (n, 0);
		def.resize (n);
		g.resize (n);

		for (int i=0; i<n; i++){
			cin >> ages[i];
			def[i] = i;
		}

		for (int i=0; i<m; i++){
			int u, v;

			cin >> u >> v;

			g[v-1].push_back (u-1);

		}


		for (int i=0; i<I; i++){
			char q;
			int u, v;

			cin >> q;

			if (q == 'T'){
				// Swap;
				cin >> u >> v;
				change (ages, def, u-1, v-1);
			}
			else {
				cin >> u;
				// query;
				int ans = dfs (g, ages, def, def[u-1]);
				if (ans == 99999999)
					cout << "*\n";
				else
					cout << ans << endl;
			}


		}

	}

	return 0;
}
