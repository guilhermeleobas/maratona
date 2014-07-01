/*
Problema - Dama
http://br.spoj.com/problems/DAMA/
Guilherme Leobas
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ab(int a, int b){
	if (a > b){
		 return (a-b);
	 }
	else {
		return (b-a);
	}
}


int main (){
	
	int x1;
	int x2;
	int y1;
	int y2;
	int dx;
	int dy;
	int distancia;
	
	while (1){
		scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) break;
	
		//Distancias nas linhas e colunas;
		dx = ab(x1, x2);
		dy = ab(y1, y2);
		
		//Distancia nas diagonais acontece apenas se dx == dy;
		if (dx == 0 && dy == 0){
			distancia = dx;
		}
		else if (dx == dy || x1 == x2 || y1 == y2){
			distancia = 1;
		}
		else {
			distancia = 2;
		}
		
		printf ("%d\n", distancia);
		
		
	}
	
	
	return 0;
}

