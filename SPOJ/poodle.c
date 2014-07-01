/*
Problema - Poodle
http://br.spoj.com/problems/POODLEMG/
Guilherme Leobas
*/

#include <stdio.h>
#include <stdlib.h>

int main (){

	int n;
	int p;
	int num_paginas;
	int cont;

	while (1){
		scanf ("%d %d", &n, &p);
		if (n == 0 && p == 0) break;

		num_paginas = n/p;

		if (num_paginas >=20){
			num_paginas = 14;
		}
		else{
			if (n%p != 0){
				num_paginas = num_paginas + 1;
			}

			num_paginas = num_paginas - 6;
		}

			printf ("P");
			for (cont=0; cont<num_paginas; cont++){
				printf ("o");
			}

		printf ("oodle\n");


	}

	return 0;
}


