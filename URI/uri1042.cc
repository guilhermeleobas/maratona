// http://www.urionlinejudge.com.br/judge/pt/problems/view/1042

#include <iostream>
#include <cmath>

using namespace std;

int main (){

	int a, b, c;
	int aa, bb, cc;

	cin >> a >> b >> c;

	aa = a;
	bb = b;
	cc = c;

	if (a > b)
		swap (a, b);
	if (b > c)
		swap (b, c);
	if (a > b)
		swap (a, b);

	cout << a << '\n' << b << '\n' << c << "\n\n";
	cout << aa << endl << bb << endl << cc << endl;
	
	return 0;
}
