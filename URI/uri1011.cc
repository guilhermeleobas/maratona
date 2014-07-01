#include <iostream>
#include <iomanip>

using namespace std;

#define PI 3.14159

int main (){

	int r;

	cin >> r;

	cout << fixed << setprecision (3) << "VOLUME = " << float((4*PI*r*r*r)/3) << endl;

	return 0;
}