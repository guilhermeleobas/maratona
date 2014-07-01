#include <iostream>
#include <set>

using namespace std;

char v[305][305];

bool valid (int n){
	
	char c = v[0][0]; 
	
	set<char> p, q;

	for (int i=0; i<n; i++){
		p.insert (v[i][i]);
		q.insert (v[i][n-i-1]);
	}

	if (!(p.size() == 1 && q.size() == 1 && *p.begin() == *q.begin()))
		return false;

	set<char> s;

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (i != j && i != n-j-1)
				s.insert (v[i][j]);

	if (s.size() != 1)
		return false;

	if (*s.begin() == *p.begin()) return false;

	return true;
}

int main (){
	
	int n;

	cin >> n;

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}

	if (valid (n))
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
