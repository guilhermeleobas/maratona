/*
Problema - O bolo de apostas
http://br.spoj.com/problems/BAPOSTAS/
Guilherme Leobas
*/

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

	int n, aux, maxsum, sum, num;

	while (true){
		cin >> n;
		if (n == 0) break;

		maxsum = 0;
		sum = 0;

		for (int cont=0; cont<n; cont++){
			scanf ("%d", &num);

			sum += num;
			if (sum < 0) sum = 0;
			if (sum > maxsum) maxsum = sum;
		}

		if (maxsum == 0){
			cout << "Losing streak.\n";
		}
		else {
			cout << "The maximum winning streak is " << maxsum << "." << endl;
		}
	}
	
	

	

	return 0;
}