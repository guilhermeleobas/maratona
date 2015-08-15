//Link: http://www.codeforces.com/problemset/problem/262/A

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;


int main (){

	int quant;
	int max;
	int lucky;
	int result=0;

	char vetor[13];

	cin >> quant >> max;

	for (int cont=0; cont<quant; cont++){
		scanf ("%s", vetor);

		lucky = 0;

		for (int aux=0; aux<strlen(vetor); aux++){
			if (vetor[aux] == '7' || vetor[aux] == '4'){
				lucky++;
			}
		}

		if (lucky <= max){
			++result;
		}
	}

	cout << result << endl;



	return 0;
}