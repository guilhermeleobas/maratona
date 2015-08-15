//Link: http://www.codeforces.com/problemset/problem/3/A

#include <iostream>
#include <cmath>

//a = 49
//b = 50
//c = 51 ...


//Se inicio - fim na HORIZONTAL < 0
//Rei está indo da Esquerda para a Direita -->

//Se inicio - fim na HORIZONTAL > 0
//Rei está indo da Direita para a Esquerda <--


//Se inicio - fim na VERTICAL > 0
//Rei está indo de cima para baixo;

//Se inicio - fim na VERTICAL < 0
//Rei está indo de baixo pra cima;


using namespace std;

int main (){

	char start[3];
	char end[3];

	int vertical;
	int horizontal;

	char v[2];
	char h[2];

	cin >> start;
	cin >> end;

	horizontal = ((int)start[0]) - ((int)end[0]);
	vertical = ((int)start[1]) - ((int)end[1]);

	if (horizontal > 0){
		h[0] = 'L';
	}
	else {
		h[0] = 'R';
	}

	if (vertical > 0){
		v[0] = 'D';
	}
	else {
		v[0] = 'U';
	}

	//NUMERO DE MOVIMENTOS;
	horizontal = abs(horizontal);
	vertical = abs(vertical);

	if (horizontal > vertical){
		cout << vertical + (horizontal-vertical) << endl;
	}
	else {
		cout << horizontal + (vertical - horizontal) << endl;
	}

	//TIPO DE MOVIMENTOS;
	while (horizontal != 0 || vertical != 0){
		if (horizontal > 0){
			cout << h[0];
			--horizontal;
		}
		if (vertical > 0){
			cout << v[0];
			--vertical;
		}
		cout << endl;
	}


	return 0;
}