/*
Problema - A niceday, The day of the competitors
Solução usando segtree
http://www.spoj.com/problems/NICEDAY/
Guilherme Leobas
*/

nclude <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

#define INF 1000000


int t, n, resp = 0;
int segtree[300010];

struct compt {
    int x, y, z;
};

compt vetor[100000+10];

void imprime (){
    for (int i=0; i<pow(2, log2(n)+1)-1; i++){
        cout << segtree[i] << ' ';
    }
    cout << endl;
}

void inicializa (int node, int l, int r){
 
    if (l > r) return;
 
    if (l == r){
        segtree[node] = INF;
    }
    else {
        inicializa (2*node+1, l, (l+r)/2);
        inicializa (2*node+2, (l+r)/2+1, r);
 
        segtree[node] = INF;
    }
 
}

int query (int node, int l, int r, int i, int j){
 
    int p1, p2;

    //size overflow;
    if (l > r || l > j || r < i)
        return -1;

    //Intervalo incluido
    if (l >= i && r <= j){
        return segtree[node];
    }
 
    p1 = query (2*node+1, l, (l+r)/2, i, j);
    p2 = query (2*node+2, (l+r)/2+1, r, i, j);

    // Condição: pai = max (fllho1, filho2);

    if (p1 == -1)
        return p2;
    if (p2 == -1)
        return p1;

    return (min(p1, p2));
}

void update (int node, int l, int r, int x, int y){

    if (l > r || l > x || r < x)
        return;

    int k = 0;

    if (l == x && r == x){     
        
        if (x-1 >= 0){
            k = query (0, 0, n-1, 0, x-1);
        }
        else
            k = INF;

         if (k > y){
             resp++;
         }

        segtree[node] = y;
        return;
    }
 
    update (2*node+1, l, (l+r)/2, x, y);
    update (2*node+2, (l+r)/2+1, r, x, y);
 
    // Condição: pai = max (fllho1, filho2);
    if (segtree[2*node+1] != INF && segtree[2*node+2] != INF){
        segtree[node] = min(segtree[2*node+1], segtree[2*node+2]);
    }
    else if (segtree[node] != INF){
        if (segtree[2*node+1] == INF){
            segtree[node] = min (segtree[node], segtree[2*node+2]);
        }
        else{
            segtree[node] = min (segtree[node], segtree[2*node+1]);
        }
    }
    else {
        if (segtree[2*node+1] == INF){
            segtree[node] = segtree[2*node+2];
        }
        else {
            segtree[node] = segtree[2*node+1];
        }
    }
}
 
bool comp (struct compt a, struct compt b){
    return a.z < b.z;
}


int main (){
    
   ios::sync_with_stdio(false);

   int a, b, c;
 
   cin >> t;

   while (t--){
        cin >> n;

        inicializa (0, 0, n-1);

        for (int i=0; i<n; i++){
            cin >> vetor[i].x >> vetor[i].y >> vetor[i].z;
       }

        sort (vetor, vetor+n, comp);

        resp = 0;

        for (int i=0; i<n; i++){
            //Add - segtree;
            update (0, 0, n-1, vetor[i].x-1, vetor[i].y);
        }

         cout << resp << endl;
   }

    return 0;
}


