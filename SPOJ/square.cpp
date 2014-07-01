//Link: http://www.codeforces.com/problemset/problem/1/A

#include <iostream>

using namespace std;

int main (){

	long long n, m, a;
	long long vert, hori;

	cin >> n >> m >> a;

	//cout << ((m+a-1)/a)*((n+a-1)/a)<< endl;


	hori = n/a;
	if (n%a != 0) hori++;

	vert = m/a;
	if (m%a != 0) vert++;
	
	cout << hori*vert << endl;

	return 0;
}
