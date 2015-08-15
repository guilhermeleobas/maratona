#include <iostream>
#include <math.h>

using namespace std;

int converte (int num, int array[32]){
	int i=31;
	
	while (num/2 != 0){
		array[i] = num%2;
		num = num/2;
		i = i - 1;
		
	}
	
	array[i] = num%2;
	
	return 32-i;
}

int main (){
	int n;
	int vetor[32];
	int cont;
	int paridade;
	int proced;
	
	while (true){
		
		//Inicialização de variaveis:
		paridade = 0;
		proced = 0;
		
		for (cont=0; cont<32; cont++){
		vetor[cont] = 0;
		}
		
		cin >> n;
		if (n == 0) break;
		
		proced = converte (n, vetor);
		
		for (cont=0; cont<32; cont++){
			if (vetor[cont] == 1){
				paridade = paridade + 1;
			}
		}
		
		cout << "The parity of ";
		
		for (cont=32-proced; cont<32; cont++){
			cout << vetor[cont];
		}
		
		cout << " is " << paridade << " (mod 2)." << endl;
		
		
	}
	
	
	return 0;
}
