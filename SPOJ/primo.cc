/*
Problema - Primo
http://br.spoj.com/problems/PRIMO/
Guilherme Leobas
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int num;
    int primo=1;

    cin >> num;

    if (num == 0 || num == 1 || num == -1 || num%2==0){
        primo = 0;
    }
    else {
        for (int cont=3; cont<sqrt(num)+1; cont=cont+2){
            if (num%cont==0){
                primo = 0;
            }
        }
    }

    if (primo){
        cout << "sim\n";
    }
    else {
        cout << "nao\n";
    }


    return 0;
}




