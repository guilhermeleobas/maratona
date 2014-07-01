// http://www.urionlinejudge.com.br/judge/pt/problems/view/1065

#include <iostream>

using namespace std;

int main (){

	int n;
	int cnt = 0;

	for (int i=0; i<5; i++){
		cin >> n;
		if (n%2 == 0)
			cnt++;
	}

	cout << cnt << " valores pares\n";

	return 0;
}