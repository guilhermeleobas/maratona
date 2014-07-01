#include <iostream>
#include <cmath>

using namespace std;

int maiorAB (int a, int b){

	return ((a+b+abs(a-b))/2);
}

int mxm (int a, int b, int c){

	int ab, ac, bc;

	ab = maiorAB (a, b);
	ac = maiorAB (a, c);
	bc = maiorAB (b, c);

	return max (ab, max (bc, ac));
}

int main (){

	int a, b, c;

	cin >> a >> b >> c;

	cout << mxm (a, b, c) << " eh o maior\n";
}