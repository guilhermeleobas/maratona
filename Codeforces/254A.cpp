//Link: http://www.codeforces.com/problemset/problem/254/A

#include <iostream>
#include <map>
#include <vector>
#include <cstdio>

using namespace std;

int main (){

	//Ints;
	int n;
	int card;

	//Map
	map<int, int> themap;
	map<int, int>::iterator it_map;

	//MultiMap;
	multimap<int, int> themultimap;
	multimap<int, int>::iterator it_multi;

	//Vector;
	vector<int> thevector;

	//File;
	FILE *in = fopen("input.txt", "r");
	FILE *out = fopen ("output.txt", "w");

	fscanf (in, "%d", &n);

	//Verifica se o n é par;
	
	for (int cont=0; cont<2*n; cont++){
		//Lê a carta;
		fscanf (in, "%d", &card);

		//Adiciona ao vector;
		thevector.push_back (card);

		//Iterator do map passa a apontar para a posição da carta;
		it_map = themap.find (card);

		//Adiciona o elemento e a posição no multimap;
		themultimap.insert (pair<int, int> (card, cont+1));

		//Se a carta não existe no map, adiciona;
		if (it_map == themap.end()){
			themap.insert (pair<int, int> (card, 1));
		}
		//Se já existe, apenas incrementa a segunda posição (it_map->second++);
		else {
			it_map->second++;
		}
	}

	//Verifica se a segunda posição de cada elemento do map é par;
	for (it_map = themap.begin(); it_map != themap.end(); it_map++){
		if (it_map->second%2 != 0){
			fprintf (out, "-1\n");
			return 0;
		}
	}

	//Imprime dois a dois as combinações do multimap.
	for (it_multi = themultimap.begin(); it_multi != themultimap.end(); it_multi++){
		fprintf (out, "%d ", it_multi->second);
		it_multi++;
		fprintf (out, "%d ", it_multi->second);
	}

	fclose (in);
	fclose (out);

	return 0;
}