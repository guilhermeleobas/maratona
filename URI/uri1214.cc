#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main (){
	
	int n;
	cin >> n;

	while (n--){
		int c;
		cin >> c;
		vector<int> v (c);
		
		int sum = 0;
		for(int i=0; i<c; i++){
			cin >> v[i];
			sum += v[i];
		}

		double avg = double(sum)/c;
		int l = 0;
		
		for (int i=0; i<c; i++)
			if (v[i] > avg)
				l++;
	
		cout << fixed << setprecision (3) << (double)(l*100)/c << "%" << endl;

	}

  return 0;
}
