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

int main (){

	ios::sync_with_stdio(false);
	
	int N, M, S;
	int x, y;
	char d, cmd;
	char matriz[110][110];

	while (true){
		cin >> N >> M >> S;

		if (!N && !M && !S)
			break;
		
		for (int i=0; i<N; i++){
			for (int j=0; j<M; j++){
				cin >> matriz[i][j];
				if (matriz[i][j] == 'N' || matriz[i][j] == 'S' || matriz[i][j] == 'L' || matriz[i][j] == 'O'){
					x = i;
					y = j;
				}
			}
		}

		d = matriz[x][y];
		matriz[x][y] = '.';
		int cont = 0;

		while (S--){
	
			cin >> cmd;
			
			//cout << x << ' ' << y << ' ' << d << endl;

			if (cmd == 'D'){
				if (d == 'N') d = 'L';
				else if (d == 'L') d = 'S';
				else if (d == 'S') d = 'O';
				else d = 'N';
			}

			if (cmd == 'E'){
				if (d == 'N') d = 'O';
				else if (d == 'O') d = 'S';
				else if (d == 'S') d = 'L';
				else d = 'N';
			}

			if (cmd == 'F'){
				if (d == 'N'){
					if (x - 1 >= 0 && matriz[x-1][y] != '#' ) x--;
				}
				else if (d == 'L'){
					if (y+1 < M  && matriz[x][y+1] != '#') y++;
				}
				else if (d == 'S'){
					if (x+1 < N && matriz[x+1][y] != '#') x++;
				}
				else {
					if (y-1 >= 0 && matriz[x][y-1] != '#') y--;
				}
			}
			
			if (matriz[x][y] == '*'){
				matriz[x][y] = '.';
				cont++;
			}

		}
		
		cout << cont << endl;

	}

	

	return 0;
}
