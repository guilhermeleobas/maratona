#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int getmax (vector<pair<int, int> > interv){
	
	int sum = 0;
	int last = interv[interv.size()-1].first;

	for (int i=interv.size()-2; i>=0; i--){
		if (interv[i].second < last){
			last = interv[i].first;
			sum++;
		}
	}

	return sum+1;
}	

int main(){
	
	int t;
	
	cin >> t;

	while (t--){
		
		int n;

		cin >> n;

		vector<int> v (n);

		for (int i=0; i<n; i++)
			cin >> v[i];

		for (int i=1; i<n; i++)
			v[i] += v[i-1];

		vector<pair<int, int> > interv;

		for (int i=0; i<n; i++){
			vector<int>::iterator it = lower_bound (v.begin(), v.end(), v[i]-42);
			
			if (v[i]-42 == 0){
				interv.push_back (make_pair (0, i));
			}
			else if (v[i]-42 == *it){
				interv.push_back (make_pair (it-v.begin()+1, i));
			}
		}
		
		if (interv.size() == 0)
			cout << "0\n";
		else
			cout << getmax (interv) << endl;

	}

	return 0;
}
