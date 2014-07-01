/*
    Problema - Dangerous dive
    http://www.urionlinejudge.com.br/judge/pt/problems/view/1471
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
#define CNT PI/180
#define INF 99999999
const double EPS = 1e-10;
typedef vector<vector<pair<int, int> > > graph;
 
int main (){
 
    ios::sync_with_stdio(false);
     
    int n, r;
    vector<bool> v;
 
    while (true){
        cin >> n >> r;
 
        if (!cin) break;
         
        v.clear();
        v.resize (n, false);
        for (int i=0; i<r; i++){
            int num;
            cin >> num;
            v[num-1] = 1;
        }
 
        if (n == r)
            cout << "*";;
 
        for (int i=0; i<n; i++)
            if (!v[i])
                cout << i+1 << ' ';
        cout << endl;
 
    }
 
     
 
    return 0;
}