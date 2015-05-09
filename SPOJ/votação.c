//http://br.spoj.pl/problems/POPULAR/

#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int n;
	int teste = 0;
	int ini;
	int cont;
	int dois;
	
	while (1){
		
		ini = 2;
		dois = 1;
		teste = teste + 1;
		
		scanf ("%d", &n);
		if (n == -1) break;
		
		for (cont=0; cont<n; cont++){
			ini = ini + dois;
			dois = dois*2;
		}
		
		ini = ini*ini;
		printf ("Teste %d\n", teste); 
		printf ("%d\n", ini);
		
	}
	
	
	return 0;
}
