/*
Problema - A Needle in the Haystack
http://www.spoj.com/problems/NHAY/
Guilherme Leobas
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

void pre_process (string &s, map<char, int> &m){

	for (int i=0; i<s.size(); i++){

		m[s[i]] = s.size() - i - 1;
	}

	m[s[s.size()-1]] = 1;

	// cout << s[s.size()-1] << endl;
}

int main (){

	map<char, int> m;
	map<char, int>::iterator it;
	string s, word;
	int n, aux, i;
	bool flag;
	ios::sync_with_stdio(false);

	while (true){
		cin >> n >> s >> word;

		if (!cin) break;

		m.clear();

		pre_process (s, m);

/*		for (it = m.begin(); it != m.end(); it++){
			cout << it->first << ' ' << it->second << endl;
		}
*/
		i = 0;

		flag = false;

		while (i < word.size()){

			aux = s.size()-1;

			// cout << aux << endl;
			// cout << i << endl;

			while (aux >= 0){
				if (word[i+aux] == s[aux]){
					// cout << i+aux << ' ' << aux << endl;
					aux--;
				}
				else {
					// cout << "aa\n";
					break;
				}
			}

			if (aux < 0){
				cout << i << endl;
				flag = true;
				i+= 1;
			}
			else {
				it = m.find (s[aux]);
				if (it == m.end()){
					i += s.size();
				}
				else {
					i += it->second;
				}
				// i+= m[s[aux]];
			}
		}

		if (flag == false){
			cout << endl;
		}
	}

	return 0;
}

