#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

int main(){

	map<int, int> m;
	vector<int> v, r, alt;
	int n;

	while (true){
		cin >> n;
		if (!cin) break;
	
		v.clear();
		v.resize (n+1);
		r.clear();
		r.resize (n+1);
		alt.clear();
		alt.resize (n+1);
		//m.clear();

		for (int i=1; i<=n; i++){
			cin >> v[i];
		}

		for (int i=1; i<=n; i++){
			cin >> r[i];
			//m[r[i]] = m.size();
			alt[r[i]] = i;
		}

		int ans = 0;
		for (int i=1; i<=n; i++){
			for (int j=i+1; j<=n; j++){
				if (alt[v[i]] > alt[v[j]]){
					swap (v[i], v[j]);
					ans++;
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}
