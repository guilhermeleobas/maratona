#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

#define M 500
int m[M+10][M+10];
int visit[M+10][M+10];
int r, c;
int ans = -1;

void solver (int h, int i, int j, int t){	

	//cout << i << ' ' << j << ' ' << h << ' ' << m[i][j] << ' ' << t << endl;

	visit[i][j] = 1;

	if (i == r-1 && j == c-1){
		ans = max (ans, t);
		return;
	}
	
	if (i-1 >= 0 && not visit[i-1][j] and m[i-1][j] > h+1){
		visit[i-1][j] = 1;
		solver (h+1, i-1, j, min (m[i-1][j]-h, t));
		//visit[i-1][j] = 0;
	}

	if (i+1 < r and not visit[i+1][j] and m[i+1][j] > h+1){
		visit[i+1][j] = 1;
		solver (h+1, i+1, j, min (m[i+1][j]-h, t));
		//visit[i+1][j] = 0;
	}

	if (j-1 >= 0 and not visit[i][j-1] and m[i][j-1] > h+1){
		visit[i][j-1] = 1;
		solver (h+1, i, j-1, min (m[i][j-1]-h, t));
		//visit[i][j-1] = 0;
	}

	if (j+1 < c and not visit[i][j+1] and m[i][j+1] > h+1){
		visit[i][j+1] = 1;
		solver (h+1, i, j+1, min (m[i][j+1]-h, t));
		//visit[i][j+1] = 0;
	}

}

int main (){
	
	cin >> r >> c;
	
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			cin >> m[i][j];
//			m[i][j] -= 1;
		}
	}
	

	solver (0, 0, 0, m[0][0]-1);

	if (ans == -1) cout << "-1\n";
	else cout << ans << endl;


	return 0;
}
