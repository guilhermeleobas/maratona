/*
Problema - 6139 - Interval Product
https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4150
Guilherme Leobas
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <iomanip>

using namespace std;

int segtree[1001000];
int vetor[1001000];
int n, k;

void imprime (){
    
    for (int i=0; i<pow(2, log2(n)+1); i++)
        cout << segtree[i] << ' ';
    cout << endl << endl;
}
    
void inicializa (int l, int r, int node){

    if (l > r) return;

    if (l == r){
        segtree[node] = vetor[r];
    }
    else {
        inicializa (l, (l+r)/2, 2*node+1);
        inicializa ((l+r)/2+1, r, 2*node+2);

//        cout << node << ' ' << 2*node+1 << ' ' << 2*node+2 << endl;
        segtree[node] = segtree[2*node+1]*segtree[2*node+2];
    }

}

void update (int node, int l, int r, int x){

    if (l > r || l > x || r < x)
        return;


    if (l == r){
        segtree[node] = vetor[l];
        return;
    }


    update (2*node+1, l, (l+r)/2, x);
    update (2*node+2, (l+r)/2+1, r, x);

    segtree[node] = segtree[2*node+1]*segtree[2*node+2];

}

int query (int node, int l, int r, int i, int j){

    int p1, p2;

    //size overflow;
    if (l > r || l > j || r < i)
        return -100;

    //Intervalo incluido
    if (l >= i && r <= j)
        return segtree[node];

    //
    p1 = query (2*node+1, l, (l+r)/2, i, j); 
    p2 = query (2*node+2, (l+r)/2+1, r, i, j);

   // cout << p1 << ' ' << l << ' ' << r << ' ' << i << ' ' << j << endl;

    if (p1 != -100 && p2 != -100)
        return p1*p2;
    else if (p1 == -100)
        return p2;
    else
        return p1;
}

int main (){

    char c;
    int y, x;
    int sz;

    while (true){
        cin >> n >> k;

        if (!cin)
            break;

        for (int i=0; i<n; i++){
            cin >> vetor[i];
			if (vetor[i] > 0)
				vetor[i] = 1;
			else if (vetor[i] < 0)
				vetor[i] = -1;
		}

		inicializa (0, n-1, 0);	
  //      imprime();

        for (int i=0; i<k; i++){
            cin >> c >> x >> y;

            //imprime ();

            if (c == 'C'){
                //Update;
                if (y > 0)
                    vetor[x-1] = 1;
                else if (y < 0)
                    vetor[x-1] = -1;
                else
                    vetor[x-1] = 0;
                update (0, 0, n-1, x-1);
            }
            else{
                //Query
               int r = query (0, 0, n-1, x-1, y-1);
               if (r == 0)
                   cout << '0';
               else if (r > 0)
                   cout << '+';
               else
                   cout << '-';
    //           cout << endl;
            }
        }
        cout << endl;


    }


    return 0;
}