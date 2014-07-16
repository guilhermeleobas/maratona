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

#define tam 1010

int v[tam][tam];
int n, m;

int kadane (int *arr, int size){
	int maxsum = -INF;
	int sum = 0;

	for (int i=0; i<size; i++){
		sum += arr[i];
		if (sum < 0)
			sum = 0;
		else if (sum > maxsum)
			maxsum = sum;
	}

	if (maxsum != -INF) return maxsum;

	for (int i=0; i<size; i++)
		if (arr[i] > maxsum)
			maxsum = arr[i];

	return maxsum;
}

int maxsum (){
	int arr[m];
	int maxsum = -INF;

	for (int i=1; i<=n; i++){
		for (int k=i; k<=n; k++){
			
			if (i == 1){
				for (int j=1; j<=m; j++)
					arr[j-1] = v[k][j];
			}
			else {
				for (int j=1; j<=m; j++)
					arr[j-1] = v[k][j] - v[i-1][j];
			}

			maxsum = max (maxsum, kadane (arr, m));
		}
	}
	
	return maxsum;
}


/*
int maxsum (){

	int sum = -INF;
	for (int r=1; r<=n; r++){
		for (int s=1; s<=m; s++){
			for (int p=r; p<=n; p++){
				for (int q=s; q<=m; q++){
					int aux = v[p][q] + v[r-1][s-1] - v[p][s-1] - v[r-1][q];
					// cout << aux << ' ' << p << ' ' << q << ' ' << r << ' ' << s << endl;
					sum = max (sum, aux);
				}
			}
		}
	}

	return sum;
}*/

int main (){

	ios::sync_with_stdio(false);
	
	int t;

	cin >> t;

	while (t--){
		cin >> n >> m;

		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++){
				cin >> v[i][j];
				v[i][j] += v[i-1][j];
			}
		}

		cout << maxsum () << endl;
	}
	

	

	return 0;
}
