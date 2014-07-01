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
	
	int n, t, v, soma;

	cin >> n;

	soma = 0;

	for (int i=0; i<n; i++){
		cin >> t >> v;
		soma += (t*v);
	}	

	cout << soma << endl;

	

	return 0;
}