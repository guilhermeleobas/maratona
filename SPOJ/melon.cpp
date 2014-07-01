//Link: http://www.codeforces.com/problemset/problem/4/A

#include <iostream>
#include <stdio.h>

using namespace std;

int main (){

	int num;

	while (scanf ("%d", &num) != EOF){
		if (num > 2 && num%2==0){
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}


	return 0;
}