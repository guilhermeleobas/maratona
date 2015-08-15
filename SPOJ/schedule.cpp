//Link: http://www.codeforces.com/problemset/problem/31/C

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef struct {
    int conflict;
    int start;
    int end;
    int position;
} list;

typedef vector<list> vec;

void imprime (vector<int> v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << ' ';
    }
    cout << endl;
}


int main (){

    //Vector;
    vec horario;
    vector<int> result;

    //Ints;
    int inicio;
    int fim;
    int n;
    int tamanho;
    int i;
    int soma;

    //Struct;
    list lista;

    cin >> n;

    for (int cont=0; cont<n; cont++){
        scanf ("%d", &lista.start);
        scanf ("%d", &lista.end);
        lista.position = cont;
        lista.conflict = 0;
        horario.push_back (lista);
    }
    

    tamanho = 0;
    soma = 0;

    //Verifica conflitos;
    while (tamanho < horario.size()){

        inicio = horario[tamanho].start;
        fim = horario[tamanho].end;
        i = horario[tamanho].position;

        for (int cont=i+1; cont<n; cont++){
            if (inicio < horario[cont].end && fim > horario[cont].start){
                horario[i].conflict++;
                horario[cont].conflict++;
                soma += 2;
            }
            /*  
            hora inicia 1 < hora final 2
            hora final 1 > hora inicial 2
            */
        }

        tamanho++;
    }


    if (soma == 0){
        for (int cont=0; cont<n; cont++){
            result.push_back (cont+1);
        }
    }
    else {
        for (int cont=0; cont<n; cont++){
            if (horario[cont].conflict == soma/2){
                result.push_back (cont+1);
            }
        }
    }

    cout << result.size() << endl;
    imprime (result);
    


    return 0;
}