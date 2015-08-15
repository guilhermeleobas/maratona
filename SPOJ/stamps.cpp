//Link: http://www.spoj.com/problems/STAMPS/

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

typedef deque<int> dk;

void imprime (dk d){
	
	for (dk::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << ' ';
	}
	cout << endl;

}

int main (){

	int friends, stamps, tests, borrow, cases, contador;
	deque<int> d;

	cin >> tests;

	contador=0;

	while (tests-- > 0){

		cin >> borrow;
		cin >> friends;

		cases = 0;

		d.clear();

		for (int cont=0; cont<friends; cont++){
			cin >> stamps;
			d.push_back (stamps);
		}

		sort (d.begin(), d.end());


		while (borrow > 0 && d.size() > 0){
			borrow -= d.back();
			d.pop_back();
			cases++;
		}

		cout << "Scenario #" << ++contador << ':' << endl;

		if (borrow > 0){
			cout << "impossible\n\n";
		}
		else {
			cout << cases << endl << endl;
		}

	}


	return 0;
}