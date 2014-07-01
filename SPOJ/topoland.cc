/*
Problema - To poland
http://br.spoj.com/problems/TOPOLAND/
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

int segtree[300010];
int vetor[100100];
    
void inicializa (int l, int r, int node){

    if (l > r) return;

    if (l == r){
        segtree[node] = vetor[r];
    }
    else {
        inicializa (l, (l+r)/2, 2*node+1);
        inicializa ((l+r)/2+1, r, 2*node+2);

        segtree[node] = max (segtree[2*node+1],segtree[2*node+2]);
    }

}

void update (int node, int l, int r, int x){

    if (l > r || l > x || r < x)
        return;

    if (l == x && r == x){
        segtree[node] = vetor[l];
        return;
    }

    update (2*node+1, l, (l+r)/2, x);
    update (2*node+2, (l+r)/2+1, r, x);

    segtree[node] = max(segtree[2*node+1], segtree[2*node+2]);
}

int query (int node, int l, int r, int i, int j){

    int p1, p2;

    //size overflow;
    if (l > r || l > j || r < i)
        return 0;

    //Intervalo incluido
    if (l >= i && r <= j)
        return segtree[node];

    //
    p1 = query (2*node+1, l, (l+r)/2, i, j); 
    p2 = query (2*node+2, (l+r)/2+1, r, i, j);

    return (max(p1, p2));
}

int main (){

    int t, n, m, q;
    char c[3];
    int k, j, r, s;

    scanf ("%d", &t);

    for (int test=0; test<t; test++){
        scanf ("%d%d", &n, &m);
//        printf ("%d %d\n", n, m);

        for (int i=0; i<n; i++){
            scanf ("%d", &vetor[i]);
        }

        scanf ("%d", &q);

        inicializa (0, n-1, 0);

        printf ("Testcase %d:\n", test);

        for (int i=0; i<q; i++){
            scanf ("%s", c);

            if (c[0] == 'A'){
                scanf ("%d", &k);
                m += k;
            }
            else if (c[0] == 'B'){
                //update
                scanf ("%d%d", &j, &k);
                vetor[j] = k;
                update (0, 0, n-1, j);
            }
            else {
                //query
                scanf ("%d%d", &r, &s);
                printf ("%d\n", abs(m-query(0, 0, n-1, r, s)));
            }
        }

        printf ("\n");
    }

    return 0;
}
