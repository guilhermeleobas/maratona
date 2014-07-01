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
#define cnt PI/180
#define INF 99999999
typedef vector<vector<pair<int, int> > > graph;

int mxm (int num, int d){
	if (num-d*(num/d) < 0)
		return num;
	else
		return (num-d*(num/d));
}

int main (){

	ios::sync_with_stdio(false);
	
	int num;

	cin >> num;

	cout << num << endl;
	cout << num/100 << " nota(s) de R$ 100,00\n";
	num = mxm (num, 100);
	cout << num/50 << " nota(s) de R$ 50,00\n";
	num = mxm (num, 50);
	cout << num/20 << " nota(s) de R$ 20,00\n";
	num = mxm (num, 20);
	cout << num/10 << " nota(s) de R$ 10,00\n";
	num = mxm (num, 10);
	cout << num/5 << " nota(s) de R$ 5,00\n";
	num = mxm (num, 5);
	cout << num/2 << " nota(s) de R$ 2,00\n";
	num = mxm (num, 2);
	cout << num << " nota(s) de R$ 1,00\n";

	return 0;
}
