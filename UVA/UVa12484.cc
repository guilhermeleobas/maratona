// se a sua solução não tá passando, tente otimizar a pd para utilizar somente O(n) em espaço.
// If your solution isn't passing, try to optimize the amount of memory used.

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
#include <functional>
#include <iomanip>

using namespace std;

#define PI acos(-1)
#define CNT PI/180
#define INF 99999999
const double EPS = 1e-10;
typedef vector<vector<pair<int, int> > > graph;

long long solver (vector<int> &v, vector<long long> &sum, int n){
	vector<vector<long long> > m (n+1, vector<long long> (n+1, 0));
	//vector<long long> dpa (n+1, 0), dpb (n+1, 0);
	int i=1, j=1, k=1;
  bool swp = true;
  int pointer = 1;
	while (true){
		
		long long s = sum[j] - sum[i-1];
    
		if (i == j){
			m[i][j] = v[i];
    }
		else {
			m[i][j] = s - min (m[i+1][j], m[i][j-1]);
		}
    
/*
    if (swp){
      if (i == j){
        dpa[pointer++] = v[i];
      }
      else {
        dpa[pointer] = s - min(dpb[pointer], dpb[pointer+1]);
        pointer++;
      }
    }
    else {
      if (i == j){
        dpb[pointer++] = v[i];
      }
      else {
        dpb[pointer] = s - min (dpa[pointer], dpa[pointer+1]);
        pointer++;
      }
    }
*/
    if (i == 1 and j == n){
			break;
		}
		else if (j == n){
			i = 1;
			j = 1 + k;
			k++;
      pointer = 1;
      swp = !swp;
		}
		else {
			i++; j++;
		}
	}
  
  return m[1][n];
}

int main (){

	ios::sync_with_stdio(false);
	
	while (true){
		int n;
		cin >> n;
		if (not cin) break;
		
		vector<int> v (n+1);
		for (int i=1; i<=n; i++)
			cin >> v[i];

		vector<long long> sum (n+1);
	
		sum[0] = 0;
		sum[1] = v[1];

		for (int i=1; i<=n; i++)
			sum[i] = sum[i-1] + v[i];
		
		cout << solver (v, sum, n) << endl;

	}
	
	return 0;
}
