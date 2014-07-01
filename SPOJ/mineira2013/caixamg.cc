#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	
	int a, b;
	while (true){
		cin >> a >> b;

		if (a == 0 && b == 0)
			break;

		double delta = ((4*a + 4*b)*(4*a + 4*b)) - 48*a*b;
		double x1 = (4*a+4*b) + sqrt(delta);
		x1 /= 24;

		double x2 = (4*a + 4*b) - sqrt(delta);
		x2 /= 24;

		double v1 = (a-2*x1)*(b-2*x1)*x1;
		double v2 = (a-2*x2)*(b-2*x2)*x2;

//		cou << fixed << setprecision (10) << (a-2*x2) << ' ' << (b-2*x2) << ' ' << x2 << endl;

		if (v1 > v2){
			cout << fixed << setprecision (4) << x1 << ' ' << v1 << endl;
		}
		else {
			cout << fixed << setprecision (4) << x2 << ' ' << v2 << endl;
		}	
	}

	return 0;
}
