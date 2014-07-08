#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solver (vector<int> &q, vector<int> &n){
	
	int j = q.size()-1;
	int ans = 0;
	for (int i=q.size()-1; i>=0; i--){
		if (q[i] < n[j]){
			ans++;
			j--;
		}
	}

	cout << ans << endl;
}

int main(){
	
	int s;

	cin >> s;

	vector<int> q (s);
	vector<int> n (s);

	for (int i=0; i<s; i++)
		cin >> q[i];

	for (int i=0; i<s; i++)
		cin >> n[i];

	sort (q.begin(), q.end());
	sort (n.begin(), n.end());

	solver (q, n);

	return 0;
}
