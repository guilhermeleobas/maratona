/*
Problema - Investindo no mercado de ações 1
http://br.spoj.com/problems/ACOES1MG/
Guilherme Leobas
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <stack>
#include <queue>

using namespace std;

int calc (int n, int k){

	if (n <= k){
		return 1;
	}
	
	return calc (n/2, k) + calc((n/2+n%2), k);
}


int main (){

	int n, k;
	
	while (true){
	
		cin >> n >> k;
		
		if (n == 0 && k == 0) break;
		
		cout << calc (n, k) << endl;
		
	}

	return 0;
}
