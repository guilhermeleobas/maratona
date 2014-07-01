// http://www.urionlinejudge.com.br/judge/pt/problems/view/1080

#include <iostream>

using namespace std;

int main (){

	int n = -1000, mxm;

	for (int i=0; i<100; i++){
		int num;
		cin >> num;

		if (num > n){
			n = num;
			mxm = i;
		}
	}
	cout << n << endl << mxm+1 << endl;

	return 0;
}