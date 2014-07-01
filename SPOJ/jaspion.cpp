/*
Problema - Jaspion
http://br.spoj.com/problems/JASPION/
Guilherme Leobas
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

void imprime (map<string, string> words){

	map<string, string>::iterator it;

	for (it = words.begin(); it != words.end(); it++){
		cout << it->first << ' ' << it->second << endl;
	}

}

int main (){

	// Ints;
	int t, m, n, i;

	// Strings
	string jap;
	string port;
	string name;
	string aux;

	// Map;
	map<string, string> words;
	map<string, string>::iterator it;

	cin >> t;

	while (t-- > 0){
		cin >> m >> n;

		words.clear();

		getline(cin, jap);
		for (int cont=0; cont<m; cont++){
			getline (cin, jap);
			getline (cin, port);

			// cout << jap << endl;
			// cout << port << endl;

			words.insert (make_pair<string, string> (jap, port));
		}


		for (int cont=0; cont<n; cont++){
			getline (cin, name);

			i = 0;

			while (i < name.size()){

				aux.clear();

				while (name[i] != ' ' && i < name.size()){
					aux += name[i];
					i++;
				}

				it = words.find (aux);
				if (it == words.end()){
					cout << aux;
				}
				else {
					cout << it->second;
				}

				if (name[i] == ' '){
					cout << ' ';
				}
				i++;
				
			}

			cout << endl;

		}

		cout << endl;

		// imprime (words);


	}

	return 0;
}