#include <stdio.h>
#include <stdlib.h>

int comparar(const void* a, const void* b){
    if(*(int*)a-*(int*)b>0)
        return 1;
    if(*(int*)a-*(int*)b<0)
        return -1;
    return 0;
}

int main (){
	int vetor[2000000];
	int cont;
	int n;
	int maior_preco;

	
	while (1){
		
		maior_preco = 0;
		scanf ("%d", &n);
		
		if (n==0) break;
		
		for (cont=0; cont<n; cont++){
			scanf (" %d", &vetor[cont]);
		}
		
		qsort (vetor, (size_t) n, sizeof(int), comparar);
		
		for (cont=0; cont<=n-1/2; cont++){
			if (maior_preco < vetor[cont] + vetor[n-1]){
				maior_preco = vetor[cont] + vetor[n-1];
			}
			n = n - 1;
		}
		
		printf ("%d\n", maior_preco);
	
	}
	
	return 0;
}
