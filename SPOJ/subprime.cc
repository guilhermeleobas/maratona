#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <fstream>

using namespace std;

int main (){
	
	int b, n, saldo, divida, x, y;
	bool flag;
	vector<int> v;


	while (true){
		cin >> b >> n;

		flag = false;
		v.clear();

		v.resize (b, 0);


		if (b == 0 && n == 0) break;

		for (int i=0; i<b; i++){
			cin >> saldo;
			v[i] = saldo;
		}

		for (int i=0; i<n; i++){
			cin >> x >> y >> divida;
			v[x-1] -= divida;
			v[y-1] += divida;
		}

		for (int i=0; i<v.size(); i++){
			if (v[i] < 0) flag = true;
		}

		if (flag){
			cout << "N\n";
		}
		else {
			cout << "S\n";
		}
	}
	

	

	return 0;
}