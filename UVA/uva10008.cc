#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool comp (pair<int, char> a, pair<int, char> b){
	
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

int main (){
	
	int n;
	string s;
	map<char, int> m;

	cin >> n;
	
	getline (cin, s);

	while (n--){
		getline (cin, s);

		for (int i=0; i<s.size(); i++){
			if (toupper(s[i]) >= 'A' && toupper(s[i]) <= 'Z')
				m[toupper(s[i])]++;
		}
	}

	vector<pair<int, char> > v;

	for (map<char, int>::iterator it = m.begin(); it != m.end(); it++){
		//cout << it->first << ' ' << it->second << endl;
		v.push_back (make_pair (it->second, it->first));
	}

	sort (v.begin(), v.end(), comp);

	for (int i=0; i<v.size(); i++)
		cout << v[i].second << ' ' << v[i].first << endl;

	return 0;
}
