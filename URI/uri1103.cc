#include <iostream>
#include <cmath>

using namespace std;

int main (){

	int h1, m1, h2, m2;

	while (true){

		cin >> h1 >> m1 >> h2 >> m2;

		if (!h1 && !m1 && !h2 && !m2)
			break;

		if ((h1 > h2 && m1 > m2) || (h1 == h2 && m1 > m2)){
			cout << (h2-h1+24)*60 - abs(m2-m1) << endl;
		}
		else if (h1 > h2 && m1 < m2){
			cout << (h2-h1+24)*60 + m2-m1 << endl;
		}
		else {
			cout << (h2-h1)*60 + m2-m1 << endl;
		}
	}

	return 0;
}