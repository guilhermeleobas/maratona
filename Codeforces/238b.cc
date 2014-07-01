#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int fill (vector<bool> &domino, string &s, int i){
	
	int L, R;

	domino[i] = false;

	if (s[i] == 'R'){
		R = i;
		while (i < s.size() && s[i] != 'L'){
			domino[i++] = false;
		}
		L = i;
		if (L != s.size()){
			int x = abs(L-R)-1;
			if (x%2 != 0)
				if (s[(L+R)/2] == '.') domino[(L+R)/2] = true;
		}

		return L;
	}
	else {
		while (i >= 0 && s[i] != 'R'){
			domino[i--] = false;
		}
		R = i;
		if (R >= 0){
			int x = abs(L-R)-1;
			if ((abs(L-R))%2 != 0)
				if (s[(L+R)/2] == '.') domino[(L+R)/2] = true;
		}
		return R;
	}
}

void imprime (vector<bool> &v){
	for (int i=0; i<v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
}

int main(){
	
	int n, L = -1, R = -1;
	string s;	

	cin >> n >> s;
	vector<bool> domino (n, true);

	for (int i=0; i<n; i++){
		if (s[i] == 'L' || s[i] == 'R'){
			fill (domino, s, i);
		}
	}	

	int cnt = 0;
	for (int i=0; i<n; i++)
		if (domino[i])
			cnt++;
	cout << cnt << endl;

	return 0;
}	
