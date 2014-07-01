#include <iostream>
#include <string>

using namespace std;

int main(){
	
	int n;
	string s;

	cin >> n;

	while (n--){
		cin >> s;
		bool check = true;
		for (int i=1; i<s.size(); i++){
			if (tolower(s[i-1]) >= tolower(s[i]))
				check = false;
		}

		if (check){
			cout << s << ": " << "O\n";
		}
		else {
			cout << s << ": " << "N\n";
		}
	}

	return 0;
}
