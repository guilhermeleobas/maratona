// http://www.urionlinejudge.com.br/judge/pt/problems/view/1072

#include <iostream>

using namespace std;

int main (){
	
	int N, num, in = 0, out = 0;

	cin >> N;

	for (int i=0; i<N; i++){
		cin >> num;

		if (num >= 10 && num <= 20)
			in++;
		else
			out++;
	}

	cout << in << " in\n";
	cout << out << " out\n";

	return 0;
}
