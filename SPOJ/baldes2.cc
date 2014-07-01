#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void imprime (vector<int> &v){
	for (int i=1; i<v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
}

int main (){
	
	ios::sync_with_stdio(false);

	int n, sum = 0;
	vector<int> v;

	while (true){
		cin >> n;

		if (n == 0)
			break;
		
		v.clear();
		v.resize (n+1);
		v[0] = 0;
		sum = 0;

		for (int i=1; i<=n; i++)
			cin >> v[i];

		for (int i=1; i<=n; i++){
			if (v[i] != i){
				swap (v[i], v[v[i]]);
				sum += 2*abs(i-v[i])-1;
				i--;
			}
		}
	

		if (sum%2 == 0)
			cout << "Carlos\n";
		else
			cout << "Marcelo\n";
		
	}

	return 0;
}
