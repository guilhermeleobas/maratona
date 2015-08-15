/*
Problema - Alades
http://br.spoj.com/problems/ALADES/
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

using namespace std;

int main (){

	int h1, m1, h2, m2;


	while (true){
		
		cin >> h1 >> m1 >> h2 >> m2;

		if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;

		if (h1 > h2 || (h1==h2 && (m1==m2 || m1 > m2))){
			h2+=24;
		}

		cout << 60*(h2-h1) + (m2-m1) << endl;
	}

	return 0;
}