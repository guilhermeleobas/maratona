//http://br.spoj.com/problems/TIMES1/

#include <iostream>
#include <map>
#include <stdio.h>
#include <set>

using namespace std;

//Struct;
struct Aluno {
	string nome;
	int habilidade;
};

void imprime_set (set <string> &m){

	//Iterator
	set <string>::iterator pointer;

	for (pointer = m.begin(); pointer != m.end(); pointer++){
		cout << *pointer << endl;
	}

	cout << endl;

}

void imprime_map (map <int, string> &m){

	map <int, string>::iterator pointer;

	pointer = m.end();
	pointer--;

	while (pointer != m.begin()){
		cout << pointer->first << " " << pointer->second << endl;
		pointer--;
	}
	cout << pointer->first << " " << pointer->second << endl;

}


int main (){

	//Ints;
	int quant;
	int num_times;

	//Struct auxiliar para adicionar os alunos no map;
	struct Aluno aluno;

	//Maps;
	//Armazena os alunos e sua respsectiva habilidade;
	map <int, string> elementos;

	//Set
	set <string> nomes;

	//Iterator (map);
	map<int, string>::iterator map_pointer;
	map<int, string>::reverse_iterator map_revpoint;
	map<int, string>::reverse_iterator aux;

	//Iterator (set);
	set<string>::iterator set_pointer;

	scanf ("%d %d", &quant, &num_times);

	for (int cont=0; cont<quant; cont++){
		cin >> aluno.nome;
		cin >> aluno.habilidade;

		//Adicionar ao Map;
		elementos.insert (pair<int, string> (aluno.habilidade, aluno.nome));
	}


	/*
	for (int cont=0; cont<num_times; cont++){
		cout << "Time " << cont << endl;


	}
	*/

	map_revpoint = elementos.rbegin();
	aux = elementos.rbegin();

	for (int cont=0; cont<num_times; cont++){
	
		map_revpoint = aux;
		nomes.clear();

		while (map_revpoint != elementos.rend()){

			nomes.insert (map_revpoint->second);

			//elementos.erase(map_revpoint);

			for (int aux = 0; aux<num_times; aux++){
				if (map_revpoint != elementos.rend()){
					map_revpoint++;
				}
			}

			
		}
		aux++;
		cout << "Time " << cont+1 << endl;
		imprime_set (nomes);
	}

	



	return 0;
}
