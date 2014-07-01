/*
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
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>

using namespace std;

#define PI acos(-1)
#define cnt PI/180
#define INF 99999999
typedef vector<vector<pair<int, int> > > graph;

int main (){

	ios::sync_with_stdio(false);
	
	string p1, p2, left, right;

	int a, b, meio;

	int marca = 0, continuou = 0, k = 0;

	cin >> p1 >> p2;

	meio = (p1.size() + p2.size() - 1)/2;


	for (int i=0; i<p1.size(); i++){
		if (p1[i] == '|'){
			marca = i+1;
			break;
		}
		left += p1[i];

	}

	int sz = left.size();
	
	if (left.size() < meio){
		for (int i=0; i<meio-sz && i < p2.size(); i++){
			left += p2[i];
			continuou++;
		}
	}

	for (int i=marca; i<p1.size(); i++){
		right += p1[i];
	}

	for (int i=continuou; i<p2.size(); i++){
		right += p2[i];
	}

	if (left.size() != right.size()){
		cout << "Impossible\n";
	}
	else {
		cout << left << '|' << right << endl;
	}


	return 0;
}
