#include <iostream>

using namespace std;

int main (){

	int n;
	int num, m = 0, j = 0;

	while (true){
		cin >> n;

		if (!n)
			break;

		m = 0;
		j = 0;

		for (int i=0; i<n; i++){
			cin >> num;
			if (num)
				j++;
			else
				m++;
		}

		cout << "Mary won " << m << " times and John won " << j << " times\n";
	}
}