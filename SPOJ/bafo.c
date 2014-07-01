/*
Problema - Bafo
http://br.spoj.com/problems/BAFO/
Guilherme Leobas
*/

#include <stdio.h>
#include <stdlib.h>

//Variaveis Globais;
int R;
int aldo=0;
int beto=0;
int n;
int cont;
int soma_aldo=0;
int soma_beto=0;

int main (){
    
    while (1){
      scanf ("%d", &R);
      
      if (R==0) break;
      
      for (cont=0; cont<R; cont++){
          scanf ("%d %d", &aldo, &beto);
          soma_aldo = soma_aldo + aldo;
          soma_beto = soma_beto + beto;    
      }
      
      n = n+1;
      
      if (soma_aldo > soma_beto){
         printf ("Teste %d", n);
         printf ("\nAldo\n\n");
      }
      else {
           printf ("Teste %d", n);
           printf ("\nBeto\n\n");
      }
         
      soma_aldo=0;
      soma_beto=0;    
    };
  
  system("PAUSE");	
  return 0;
}


