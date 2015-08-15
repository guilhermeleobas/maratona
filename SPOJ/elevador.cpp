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

using namespace std;

int main (){

	int c, n, x, soma, op;

	cin >> c >> n;

	soma = 0;
	op = 0;

	int cont = 0;

	while (cont++ < c){
		cin >> x;
		soma -= x;
		cin >> x;
		soma += x;

		if (soma > n){
			cout << "S\n";
			break;
		}
	}

	cout << "N\n";


	return 0;
}