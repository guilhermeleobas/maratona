#include <iostream>
#include <cmath>

using namespace std;

long long to_int (string num){
	
	int exp = 0;
	long long ans = 0;

	for (int i=num.size()-1; i>=0; i--){
		if (num[i] <= '9'){
			ans += pow(36,exp)*((char)num[i]-'0');
		}
		else {
			ans += pow(36,exp)*((char)num[i]-55);
		}
		exp++;
	}

	return ans;
}

string to_string (long long result){
	
	string ans;
	while (result > 0){
		if (result%36 < 10){
			ans += (char)(result%36) + '0';
		}
		else {
			ans += (char)(result%36)+'7';
		}
		result = result/36;
	}

	return ans;
}

int main(){

	long long a, b;
	
	string n1, n2;

	while (true){
		cin >> n1 >> n2;

		if (n1 == "0" && n2 == "0")
			break;

		
		string ans = to_string (to_int(n1)+to_int(n2));

		for (int i=ans.size()-1; i>=0; i--)
			cout << ans[i];
		cout << endl;
	}
	return 0;
}
