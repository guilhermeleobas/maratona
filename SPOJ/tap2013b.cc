#include <iostream>
#include <cmath>

using namespace std;


int ans (float f[15], float big, int n){
	
	for (int i=0; i<n; i++){
		if (f[i] >= 45) return 1;
		else f[i] = abs (f[i]-big);
	}

	if (big < 40) return 2;

	for (int i=0; i<n; i++)
		if (f[i] != 0 && f[i] < 10.0) return 2;

	return 1;
}

int main ()
{

	float f[15];
	int n;

	cin >> n;
	
	int sum = 0;

	for (int i=0; i<n; i++){
		cin >> f[i];
		sum += f[i];
	}
	
	float big = 0;
	for (int i=0; i<n; i++){
		f[i] = (f[i]*100)/sum;
		big = max (big, f[i]);
	}

	cout << ans (f, big, n) << endl;
	
	return 0;
}
