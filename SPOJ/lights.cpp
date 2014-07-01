//Link: http://www.codeforces.com/problemset/problem/275/A

#include <iostream>

using namespace std;

void modifica (int (*vetor)[4], int i, int j){
	if (i>=1 && i<=3){
		if (j>=1 && j<=3){
			if (vetor[i][j] == 1){
				vetor[i][j] = 0;
			}
			else {
				vetor[i][j] = 1;
			}
		}
	}
}

int main (){

	int vetor[4][4];
	int result[4][4];
	int aux;
	int i, j;

	//Inicializa o vetor com os botões que o jogador iŕa apertar.
	//Vale mencionar que se o numero de vezes que o jogador apertar um botão for par, então esse botão não irá afetar a sua vizinhança;
	for (i=1; i<=3; i++){
		for (j=1; j<=3; j++){
			cin >> aux;
			if (aux % 2 == 0){
				vetor[i][j] = 0;
			}
			else {
				vetor[i][j] = 1;
			}
		}
	}

	//Inicializa o arranjo do jogo;
	for (i=1; i<=3; i++){
		for (j=1; j<=3; j++){
			result[i][j] = 1;
		}
	}

	//Faz as modificações com base nos botões apertados pelo jogador;
	for (i=1; i<=3; i++){
		for (j=1; j<=3; j++){
			if (vetor[i][j] == 1){
				modifica (result, i, j);
				modifica (result, i-1, j);
				modifica (result, i, j-1);
				modifica (result, i, j+1);
				modifica (result, i+1, j);
			}
		}
	}

	//Imprime o resultado;
	for (i=1; i<=3; i++){
		for (j=1; j<=3; j++){
			cout << result[i][j];
		}
		cout << endl;
	}


	return 0;
}