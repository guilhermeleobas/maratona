// https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=3061

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main(){

	int n, k, t;
	queue<pair<int, int> > q;
	vector<vector<int> > v;
	vector<int> forca;
	cin >> t;

	while (t--){
		cin >> n >> k;
		
		forca.clear();
		v.clear();
		v.resize (pow(2, n));

		for (int i=0; i<pow(2, n); i++){
			int comp; 
			cin >> comp;
			forca.push_back (comp);
			q.push (make_pair (comp, i));
		}	

		while (q.size() > 1){
			pair<int, int> a = q.front(); q.pop();
			pair<int, int> b = q.front(); q.pop();
	
//			cout << a.second << " vs " << b.second << endl;
		
			if (a.first == b.first){
				if (a.second < b.second){
					// a.first = min (forca[a.second], k);
					q.push (a);
					v[a.second].push_back (b.second);
				}
				else {
					// b.first = min (forca[b.second], k);
					q.push (b);
					v[b.second].push_back (a.second);
				}
			}
			else if (a.first > b.first){
				a.first = min (a.first - b.first + k, forca[a.second]);
				v[a.second].push_back (b.second);
				q.push(a);
			}
			else {
				b.first = min (b.first - a.first + k, forca[b.second]);
				v[b.second].push_back (a.second);
				q.push (b);
			}
		}

		pair<int, int> r = q.front();
		q.pop();

		cout << r.second+1 << "\n";
		for (int i=0; i<v[r.second].size(); i++){
			cout << v[r.second][i]+1;
			if (i+1 < v[r.second].size()) cout << ' ';
		}
		cout << endl;
	}


	return 0;
}
