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

bool test1 (vector<int> &a, vector<int> &b, vector<int> &w){
	
	for (int i=0; i<a.size(); i++)
		if (a[i] != w[i])
			return false;

	return true;
}

bool test2 (vector<int> a, vector<int> b, vector<int> w){
	
	for (int i=0; i<a.size(); i++)
		if (b[i] != w[i])
			return false;

	return true;
}

bool test3 (vector<int> a, vector<int> b, vector<int> w){
	
	for (int i=0; i<a.size(); i++){
		int x = a[i]<b[i]? a[i] : b[i];
		if (x != w[i])
			return false;
	}

	return true;
}

bool test4 (vector<int> a, vector<int> b, vector<int> w){
	
	for (int i=0; i<a.size(); i++){
		int x = a[i]<b[i]?b[i]:a[i];
		if (x != w[i])
			return false;
	}

	return true;
}

class ComparerInator {
	public:
	int makeProgram(vector <int> A, vector <int> B, vector <int> wanted) {
		
		if (test1(A, B, wanted))
			return 1;
		if (test2(A, B, wanted))
			return 1;
		if (test3(A, B, wanted))
			return 7;
		if (test4 (A, B, wanted))
			return 7;

		return -1;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
