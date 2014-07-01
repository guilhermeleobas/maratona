// http://www.urionlinejudge.com.br/judge/pt/problems/view/1260

#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

int main (){
	
	int n;
	int sz = 0;
	string s;

	cin >> n;
	getline (cin, s);
	getline (cin, s);
	
	while (n--){
		
		map<string, int> mapa;
		sz = 0;

		while (true){
			getline (cin, s);
			if (s.size() == 0) break;

			sz++;

			mapa[s]++;

		}

		for (map<string, int>::iterator it = mapa.begin(); it != mapa.end(); it++){
			double ans = (double)it->second/sz;
			ans*=100;
			cout << fixed << setprecision (4) << it->first << ' ' << ans << endl;
		}
		if (n) cout << endl;
	}

	
	return 0;
}
