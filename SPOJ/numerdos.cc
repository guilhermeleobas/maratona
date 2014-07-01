/*
Problema - Numero de Erdos
http://br.spoj.com/problems/NUMERDOS/
Guilherme Leobas
*/

#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

vector<int> buscaalargura(vector<set<pair<string,string> > > graph , map <pair<string,string> ,int> controle ){
	vector<int> resultado;
	queue<int> fila;
	int aux;

	resultado.resize(graph.size());
	for(int i = 0 ; i < graph.size(); i++){
		resultado[i] = 0;
	}


	fila.push(0);
	while(!fila.empty()){
		aux = fila.front();
		fila.pop();
		
		for(set<pair<string,string> > :: iterator it = graph[aux].begin(); it != graph[aux].end(); it++){
			if(resultado[controle[*it]] == 0 && controle[*it] != 0){
				resultado[controle[*it]] = resultado[aux]+1;
				fila.push(controle[*it]);
			}
		}

	}

	return resultado;
}

int main(){
	int artigos,contador = 0;
	char buffer[200];
	string aux;
	vector<set<pair<string,string> > > graph;
	pair<string,string> nome;
	map <pair<string,string> ,int> controle;
	map <pair<string,string> ,int>::iterator it;
	vector<pair<string,string> > temp;
	vector<pair<string,string> > :: iterator vit,uit;
	vector<int> resultado;

	while(true){
		resultado.clear();
		graph.clear();
		controle.clear();
		temp.clear();

		contador++;
		cin >> artigos;

		if(artigos == 0)
			break;

		controle.insert(make_pair(make_pair("Erdos","P."),0));

		cin.getline(buffer,200);
		for(int i = 0 ; i < artigos ; i++){
			cin.getline(buffer,200);
			for(int j = 0 ; j < strlen(buffer) ; j++){
				if(buffer[j] != '.' && buffer[j] != ',' && buffer[j] != ' '){
					aux += buffer[j]; 
				}else if( buffer[j] == '.' && j != strlen(buffer)-1  ){
					aux+='.';
					nome.second = aux;
					aux.clear();
				} else if(buffer[j] != ' '){
					nome.first = aux;
					aux.clear();
					it = controle.find(nome);
					if(it == controle.end()){
						controle.insert(make_pair(nome,controle.size()));
					}
					temp.push_back(nome);
				}
			}

			graph.resize(controle.size());
			for(vit = temp.begin() ; vit != temp.end() ;vit++){
				for(uit = temp.begin() ; uit != temp.end() ;uit++){
					if(*vit!=*uit){
						graph[controle[*vit]].insert(*uit);
						graph[controle[*uit]].insert(*vit);
					}
				}
			}

			temp.clear();
		}
		
		resultado = buscaalargura(graph,controle);

		printf("Teste %d\n",contador );
		for(it = controle.begin() ; it != controle.end(); it++){
			if(it->second != 0){
				cout << it->first.second << " " << it->first.first << ": ";
				
				if(resultado[it->second]  == 0){
					printf("infinito\n");
				}else{
				cout << resultado[it->second] << endl;
				}
			}
		}
		printf("\n");



	}


	return 0;
}

