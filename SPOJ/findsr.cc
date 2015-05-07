// http://www.spoj.com/problems/FINDSR/

#include <string>
#include <iostream>
#include <vector>


using namespace std;

vector<int> get_divisor (int n){
	vector<int> d;
	for (int i=1; i<=n; i++){
		if (n%i == 0)
			d.push_back (i);
	}

	return d;
}

bool test (string s, int k){
	string aux (s.begin(), s.begin()+k);

	int b = s.size()/k;

	for (int i=0; i<b; i++){
		for (int j=0; j<aux.size(); j++){
			if (s[i*k + j] != aux[j]){
				//cout << "nao deu matching entre: " << s[i] << i << ' ' << aux[j] << j << endl;
				return false;
			}
		}
	}
	
	return true;
}

void solver (string s){
	vector<int> d = get_divisor (s.size());

	for (int i=0; i<d.size(); i++){
		if (test (s, d[i])){
			cout << s.size()/d[i] << endl;
			return;
		}
	}

}

int main (){
	
	while (true){
		string s;
		cin >> s;
		
		if (s == "*")
			break;

		solver (s);
	}

	return 0;
}
