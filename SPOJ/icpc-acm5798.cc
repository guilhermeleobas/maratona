/*
Problema - Jupiter attacks
https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=531&page=show_problem&problem=3809
Guilherme Leobas
*/

#include <iostream>
#include <string>
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
#include <functional>
#include <iomanip>

using namespace std;

#define PI acos(-1)
#define cnt PI/180
#define INF 99999999
typedef vector<vector<pair<int, int> > > graph;

long long segtree[300010];
long long B, Pm, L, N;

//A função irá retornar um inteiro P = (a^e)%n;
long long exp (long long a, long long e, long long n){

    int P = 1;
    
    while (e != 0){

        if (e % 2 != 0){
            P = (a*P)%n;
            e = (e-1)/2;
        }
        else {
            e = e/2;
        }

        a = (a*a)%n;
    }

    return P;
}
    
void inicializa (int node, int l, int r){

    if (l > r) return;

    if (l == r){
        segtree[node] = 0;
    }
    else {
        inicializa (2*node, l, (l+r)/2);
        inicializa (2*node+1, (l+r)/2+1, r);

        segtree[node] = 0;
    }

}

void update (int node, int l, int r, int pos, long long value){

    long long sz = (l+r)/2;

    if (l > r || l > pos || r < pos)
        return;

    if (l == pos && r == pos){
        segtree[node] = value;
        return;
    }

    update (2*node, l, (l+r)/2, pos, value);
    update (2*node+1, (l+r)/2+1, r, pos, value);

    segtree[node] = ( (segtree[2*node]*exp(B, r-sz, Pm)%Pm) + segtree[2*node+1] )%Pm;
}

pair<long long, int> query (int node, int l, int r, int i, int j){

    pair<long long, int> p1, p2;

    //size overflow;
    if (l > r || l > j || r < i)
        return make_pair(-1, 0);


    //Intervalo incluido
    if (l >= i && r <= j){
        return make_pair (segtree[node]%Pm, r-l+1);
    }

    p1 = query (2*node, l, (l+r)/2, i, j); 
    p2 = query (2*node+1, (l+r)/2+1, r, i, j);

    if (p1.first == -1)
        return make_pair (p2.first%Pm, p2.second);
    if (p2.first == -1)
        return make_pair (p1.first%Pm, p1.second);

    return make_pair ( ( ( exp(B, p2.second, Pm)*p1.first)%Pm + p2.first)%Pm, p1.second+p2.second);
}

int main (){

    ios::sync_with_stdio(false);
    
    long long value;
    int px, py, pos;
    char cmd;
    
    while (true){

        cin >> B >> Pm >> L >> N;

        if (!B && !Pm && !L && !N)
            break;

        inicializa (1, 1, L);

        for (int i=0; i<N; i++){
            cin >> cmd;

            if (cmd == 'E'){
                // Update;
                cin >> pos >> value;
                // cout << pos << ' ' << value << endl;
                update (1, 1, L, pos, value);
                // cout << endl;
            }
            else {
                // Query;
                cin >> px >> py;
                cout << (query (1, 1, L, px, py).first)%Pm << endl;
            }
        }

        cout << "-\n";

/*        for (int i=0; i<10; i++)
            cout << segtree[i] << ' ';
        cout << endl;*/
    }

    

    return 0;
}
