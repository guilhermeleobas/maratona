/*
Problema - Quermesse
http://br.spoj.com/problems/QUERM/
Guilherme Leobas
*/

#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int vetor[10000];
	int n;
	int cont;
	int teste = 0;
	
	while (1){
		teste = teste + 1;
		scanf ("%d", &n);
		if (n == 0) break;
		
		for (cont=0; cont<n; cont++){
			scanf ("%d ", &vetor[cont]);
			if (vetor[cont] == cont+1){
				printf ("Teste %d\n", teste);
				printf ("%d\n", vetor[cont]);
			}
		}
		
		
			
		
	}
	
	
	return 0;
}


