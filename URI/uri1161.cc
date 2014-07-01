#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main (){

	map<int, long long> mapa;

	mapa[0] = 1;
	for (int i=1; i<=20; i++){
		mapa[i] = mapa[i-1]*i;
	}

	
	int m, n;
	
	while (cin >> m >> n){

		cout << mapa[m]+mapa[n] << endl;
	}

	return 0;
}
