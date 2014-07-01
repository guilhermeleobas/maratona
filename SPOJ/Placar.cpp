/*
Problema - Quem vai ser reprovado
http://br.spoj.com/problems/PLACAR/
Guilherme Leobas
*/

#include <iostream>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

typedef struct {
	string nome;
	int nota;
} info_aluno;


int main (){

	//Info do aluno;
	info_aluno aluno[100]; //Criar um vetor do tipo aluno;
	int num_casos = 0;
	int instancia = 0;

	//Menor elemento
	int menor;

	//Variaveis do map;
	map<string, int> MyMap;
	
	//Criar o iterator:
	map<string, int>::iterator pointer;

	while (scanf ("%d", &num_casos) != EOF){
		
		MyMap.clear();


		//Ler os valores do struct;
		for (int cont=0; cont<num_casos; cont++){
			cin >> aluno[cont].nome;
			cin >> aluno[cont].nota;
		}


		//Calcula a menor nota;
		for (int cont=0; cont<num_casos; cont++){
			if (cont==0){
				menor = aluno[cont].nota;
			}
			else {
				if (menor > aluno[cont].nota){
					menor = aluno[cont].nota;
				}
			}
		}

		//Inicializa o vetor;
		for (int cont=0; cont<num_casos; cont++){
			if (aluno[cont].nota == menor){
				MyMap.insert (pair<string, int> (aluno[cont].nome, aluno[cont].nota));
			}
		}

		pointer = MyMap.end();

		--pointer;

		cout << "Instancia " << ++instancia << endl;
		cout << pointer->first << endl;
	}

	return 0;
}
