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
	
	int n, m;
  cin >> n;

  vector<int> boy (n);
  for (int i=0; i<n; i++)
    cin >> boy[i];

  cin >> m;
  vector<int> girl (m);
  for (int i=0; i<m; i++)
    cin >> girl[i];

  sort (boy.begin(), boy.end());
  sort (girl.begin(), girl.end());
  
  int count = 0;
  for (int i=0; i<boy.size(); i++){
    for (int j=0; j<girl.size(); j++){
      if (abs(boy[i]-girl[j]) <= 1){
        girl.erase (girl.begin() + j);
        count++;
        break;
      }
    }
  }


  cout << count << endl;

	

	return 0;
}
