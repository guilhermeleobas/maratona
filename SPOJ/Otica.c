//http://br.spoj.pl/problems/LOTICA/

#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int n;
	int vetor[5];
	int cont;
	int resposta;
	int true;

	
	while (1){
		
		scanf ("%d", &n);
		if (n == 0) break;
		
		
		for (cont=0; cont<n; cont++){
			
			true = 0;
			
			scanf ("%d %d %d %d %d", &vetor[0], &vetor[1], &vetor[2], &vetor[3], &vetor[4]);
			
			if (vetor[0] <= 127){
				true = true + 1;
				resposta = 0;
			}
			if (vetor[1] <= 127){
				true = true + 1;
				resposta = 1;
			}
			if (vetor[2] <= 127){
				true = true + 1;
				resposta = 2;
			}
			if (vetor[3] <= 127){
				true = true + 1;
				resposta = 3;
			}
			if (vetor[4] <= 127){
				true = true + 1;
				resposta = 4;
			}
		
			if (true != 1){
				printf ("*\n");
			}
			else {
				if (resposta == 0) printf ("A\n");
				if (resposta == 1) printf ("B\n");
				if (resposta == 2) printf ("C\n");
				if (resposta == 3) printf ("D\n");
				if (resposta == 4) printf ("E\n");
			}
		
		}
		
	}
	
	return 0;
}

