//http://br.spoj.pl/problems/CHAMADA1/

#include <stdio.h>
#include <stdlib.h>

//Variaveis globais:
typedef struct vetor{
	char nome[21];
} abc;

int comparar (const void *valor1,const void *valor2)
{
  return strcmp((char *)valor1,(char *)valor2);
}

int main (){
	
	int n;
	int k;
	int cont;
	abc c[100];
	
	
	scanf ("%d %d", &n, &k);
		
		
	for (cont=0; cont<n; cont++){
		scanf ("%s", c[cont].nome);
	}
		
	qsort (c, n, sizeof(abc), comparar);
		
	printf ("%s", c[k-1].nome);

	return 0;
}
