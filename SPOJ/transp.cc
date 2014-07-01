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
	
	int a, b, c;
	int x, y, z;

	cin >> a >> b >> c;
	cin >> x >> y >> z;

	a = x/a;
	b = y/b;
	c = z/c;

	cout << a*b*c << endl;
	

	return 0;
}