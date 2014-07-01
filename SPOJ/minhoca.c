/*
Problema - Minhoca
http://br.spoj.pl/problems/MINHOCA/
Guilherme Leobas
*/

#include <stdio.h>
#include <stdlib.h>
 
int main (){
	int vetor[100][100];
	int linha;
	int coluna;
	int i, j;
	int soma_i;
	int soma_j;
	int total_i;
	int total_j;
	
	scanf ("%d %d", &linha, &coluna);
	
	for (i=0; i<linha; i++){
		for (j=0; j<coluna; j++){
			scanf ("%d ", &vetor[i][j]);
		}
	}
	
	
	for (i=0; i<linha; i++){
		soma_i = 0;
		for (j=0; j<coluna; j++){
			soma_i = soma_i + vetor[i][j];
		}
		if (i != 0){
			if (soma_i > total_i){
				total_i = soma_i;
			}
		}
		else {
			total_i = soma_i;
		}
	}
	
	for (j=0; j<coluna; j++){
		soma_j = 0;
		for (i=0; i<linha; i++){
			soma_j = soma_j + vetor[i][j];
		}
		if (j != 0){
			if (soma_j > total_j){
				total_j = soma_j;
			}
		}
		else {
			total_j = soma_j;
		}
	}
	
	if (total_i > total_j){
		printf ("%d", total_i);
	}
	else {
		printf ("%d", total_j);
	}
			
		return 0;
}


