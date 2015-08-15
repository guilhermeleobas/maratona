//Problem link: http://br.spoj.com/problems/ELEICOES/
//Owner: Guilherme Leobas;

#include <iostream>
#include <map>

using namespace std;

int main (){

	//Variaveis;
	int votos;
	int candidato;
	int maior=0;

	//Map;
	map <int, int> eleicao;

	//Iterator;
	map <int, int>::iterator pointer;

	//Ler o numero de eleitores;
	cin >> votos;

	for (int cont=0; cont<votos; cont++){
		cin >> candidato;

		pointer = eleicao.find(candidato);
		if (pointer != eleicao.end()){
			++pointer->second;
		}
		else {
			eleicao.insert (pair<int, int> (candidato, 1));
		}
	}


	//Pega o candidato que teve o maior numero de votos;
	pointer = eleicao.begin();

	while (pointer != eleicao.end()){
		if (maior < pointer->second){
			maior = pointer->second;
		}
		++pointer;
	}


	//Imprime o numero do candidato que teve o maior numero de votos;
	pointer = eleicao.begin();

	while (maior != pointer->second){
		++pointer;
	}

	cout << pointer->first;


	


	return 0;
}