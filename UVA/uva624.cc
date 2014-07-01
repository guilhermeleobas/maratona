#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void display (vector<int> &v, int k, int ss){
	
	for (int i=0; i<k; i++)
		if ((1 << i) & ss)
			cout << v[i] << ' ';
}

int len (vector<int> &v, int k, int n, int subset){
	int sum = 0;
	for (int i=0; i<k; i++)
		if ((1<<i) & subset)
			sum += v[i];
	return sum <= n ? sum : -1;
}

void bt (vector<int> &v, int n, int k){

	int limit = pow (2, k);
	int subset = 0;
	int sum = 0;
	int ss = 0;
	while (subset < limit){
		int aux = len (v, k, n, subset);
		if (sum < aux){
			sum = aux;
			ss = subset;
		}
		else if (sum == aux &&  __builtin_popcount(ss) < __builtin_popcount(subset)){
			ss = subset;
			//cout << sum << ' ' << subset << endl;
		}
		subset++;
	}

	display (v, k, ss);
	cout << "sum:" << sum << endl;
}

int main (){
	
	while (true){
		int n, k;
		cin >> n >> k;
		
		if (not cin) break;

		vector<int> v (k);

		for (int i=0; i<k; i++)
			cin >> v[i];
		
		bt (v, n, k);
	}

	
	return 0;
}
