#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>

using namespace std;

#define pi cos(-1)
#define cnt PI/180
typedef vector<vector<pair<int, int> > > graph;

int vetor[50500];

int bsearch (int num, int n){
	
	int l, r, m;

	l = 0;
	r = n;

	while (l < r){
		m = (l + r)/2;
		// cout << "Left: " << l << "\t Right: " << r << "\t M: " << m << endl;
		// cout << m << ' ' << l << ' ' << r << endl;

		if (vetor[m] == num){
			break;
			// cout << "asl\n";
		}
		else if (vetor[m] < num){
			l = m+1;
			// cout << "b\n";
		}
		else {
			r = m;
			// cout << "c\n";
		}
	}

	while (m >= 0 && vetor[m] == num){
		if (vetor[m-1] == num) m--;
		else break;
	}

	if (vetor[m] == num) return m;
	else return -1;
}

int main (){

	int n, k, num;

	scanf ("%d%d", &n, &k);

	for (int i=0; i<n; i++){
		scanf ("%d", &vetor[i]);
	}

	for (int i=0; i<k; i++){
		scanf ("%d", &num);

		if (num < vetor[0]){
			printf ("-1\n");
		}
		else if (num > vetor[n-1]){
			printf ("-1\n");
		}
		else {
			printf ("%d\n", bsearch (num, n));
		}
	}

	return 0;
}

