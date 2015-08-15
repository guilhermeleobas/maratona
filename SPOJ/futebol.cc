/*
Problema - Output pra baralho!!!!!!!!
http://br.spoj.com/problems/PLACAR/
Guilherme Leobas
*/

#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <locale>

using namespace std;

typedef struct {
	string nome;			// Nome;
	int posicao; 			// Posição do time;
	int pontos;				// # de pontos;
	int jogos;   			// # de jogos disputados;
	int gols_marcados;		// # de gols marcados;
	int gols_sofridos;		// # de gols sofridos;
	int saldo_gols;			// Saldo de gols;
	double porcentagem;		// Porcentagem de pontos ganhos;
	int result;
} times;

bool sortme (times a, times b){

	// a.result = 100*a.pontos + 10*a.saldo_gols + a.gols_marcados;
	// b.result = 100*b.pontos + 10*b.saldo_gols + b.gols_marcados;

	if (!(a.pontos == b.pontos)){
		return a.pontos > b.pontos;
		// return false;
	}
	else if (!(a.saldo_gols == b.saldo_gols)){
		return a.saldo_gols > b.saldo_gols;
		// return false;
	}
	else if (!(a.gols_marcados == b.gols_marcados)){
		return a.gols_marcados > b.gols_marcados;
		// return false;
	}
	else {
		return strcasecmp (a.nome.c_str(), b.nome.c_str()) < 0;
		// return true;
	}

}

bool compare (times a, times b){
	if (a.pontos == b.pontos){
		if (a.saldo_gols == b.saldo_gols){
			if (a.gols_marcados == b.gols_marcados){
				return true;
			}
		}
	}

	return false;
}



int main (){
	
	// Map;
	map<string, int> m;

	// vetor;
	// times ti[29];
	vector<times> ti;

	// ints;
	int t, g, g1, g2;
	int i, j, k;

	// String;
	string t1, t2, aux;

	while (true){
		cin >> t >> g;
		if (t == 0 && g == 0) break;

		k = 0;

		ti.clear();
		ti.resize (t);
		m.clear();

		for (int cont=0; cont<t; cont++){
			cin >> ti[cont].nome;
			ti[cont].posicao = 0;
			ti[cont].pontos = 0;
			ti[cont].jogos = 0;
			ti[cont].gols_marcados = 0;
			ti[cont].gols_sofridos = 0;
			ti[cont].saldo_gols = 0;
			ti[cont].porcentagem = 0;
			ti[cont].result = 0;
			m.insert (make_pair (ti[cont].nome, cont));
		}

		for (int cont=0; cont<g; cont++){
			cin >> t1 >> g1 >> aux >> g2 >> t2;

			i = m[t1];
			j = m[t2];

			// # de gols marcados e sofridos;
			ti[i].gols_marcados += g1;
			ti[i].gols_sofridos += g2;

			ti[j].gols_marcados += g2;
			ti[j].gols_sofridos += g1;

			// Jogos disputados;
			ti[i].jogos += 1;
			ti[j].jogos += 1;

			// Saldo de gols;
			ti[i].saldo_gols += (g1-g2);
			ti[j].saldo_gols += (g2-g1);

			// Verifica ganhador;
			if (g1 > g2){
				ti[i].pontos += 3;
			}
			else if (g1 < g2){
				ti[j].pontos += 3;
			}
			else {
				ti[i].pontos += 1;
				ti[j].pontos += 1;
			}

		}

		// Porcentagem de pontos;
		for (int cont=0; cont<t; cont++){
			if (ti[cont].jogos != 0){
				ti[cont].porcentagem = (double)100*ti[cont].pontos/(3*ti[cont].jogos);
			}
			else {
				ti[cont].porcentagem = -1;
			}

		}

		/*for (int cont=0; cont<t; cont++){
			ti[cont].result = 100*ti[cont].pontos + 10*ti[cont].saldo_gols + ti[cont].gols_marcados;
		}*/
		
		sort (ti.begin(), ti.end(), sortme);

		printf (" 1. %15s %3d %3d %3d %3d %3d", ti[0].nome.c_str(), ti[0].pontos, ti[0].jogos, ti[0].gols_marcados, ti[0].gols_sofridos, ti[0].saldo_gols);
		if (ti[0].porcentagem < 0){
			printf ("    N/A");
		}
		else {
			printf ("%7.2lf", ti[0].porcentagem);
		}
		cout << endl;
		k = 2;

		for (int cont=1; cont<t; cont++){
			
			// if (ti[cont].result == ti[cont-1].result){
			if ( compare (ti[cont], ti[cont-1]) ){
				printf ("   ");
			}
			else {
				printf ("%2d.", k);
			}
			
			printf ("%16s%4d %3d %3d %3d %3d", ti[cont].nome.c_str(), ti[cont].pontos, ti[cont].jogos, ti[cont].gols_marcados, ti[cont].gols_sofridos, ti[cont].saldo_gols);
			if (ti[cont].porcentagem < 0){
				printf ("    N/A");
			}
			else {
				printf ("%7.2lf", ti[cont].porcentagem);
			}
			cout << endl;
			k++;
		}

		cout << endl;
		
	}

	return 0;
}