#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<int> s1;
vector<int> s2;

void print (vector<int> &s){
	
	for (int i=0; i<s.size(); i++)
		cout << s[i] << ' ';
	cout << endl;

}

int count (vector<int> &s, int num){
	
	vector<int>::iterator l, u;

	l = lower_bound (s.begin(), s.end(), num);
	u = upper_bound (s.begin(), s.end(), num);

	if (*u < num) return 0;
	if (*l > num) return 0;
	
	return u-l;
}

int main(){
	
	cin >> n;

	vector<int> a (n), b (n), c (n), d (n);

	for (int i=0; i<n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	s1.resize (n*n);
	s2.resize (n*n);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			s1[i*n + j] = a[i] + b[j];
			s2[i*n + j] = c[i] + d[j];
			//cout << i*n + j << endl;
		}
	}

	sort (s2.begin(), s2.end());
	int sum = 0;
	for (int i=0; i<s1.size(); i++){
		sum += count (s2, -s1[i]);
	}

	cout << sum << endl;

	return 0;
}
