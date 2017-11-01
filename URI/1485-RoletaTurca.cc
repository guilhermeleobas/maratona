#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 250
#define INF 0x3f3f3f3f

int r[MAX+10];
int b[MAX+10];
int pd[MAX+10][MAX+10];

#define min(a, b) a > b? b : a

int solve (int b_size, int r_size){


  // cout << "comecou: \n";
  // for (int i=0; i<r_size; i++)
  //   cout << r[i] << ' ';
  // cout << endl;

  int minimo = INF;

  int j = 0;
  int i = 0;
  for (j=0; j<r_size; j++){
    if (j == 0)
      pd[0][j] = INF;
    else
      pd[0][j] = b[0]*r[j-1] + b[0]*r[j];
  }

  for (i=1; i<b_size; i++){
    int aux = INF;
    for (j=0; j<r_size; j++){
      if (j <= 2)
        pd[i][j] = INF;
      else{
        aux = min(aux, pd[i-1][j-2]);
        // cout << "aux: " << aux << endl;

        if (aux == INF)
          pd[i][j] = INF;
        else
          pd[i][j] = aux + (b[i]*r[j-1] + b[i]*r[j]);
      }
    }
  }

  return pd[b_size-1][r_size-1];

  // print(b_size, r_size);
}

void shifta(int r_size){
  int aux;
  int aux2 = r[0];
  int i = 1;
  for (i=1; i<r_size; i++){
    aux = r[i];
    r[i] = aux2;
    aux2 = aux;
  }
  r[0] = aux2;
}

int main (){

  while (1){
    int r_size, b_size;
    
    scanf("%d%d", &r_size, &b_size);

    if (r_size == 0 && b_size == 0) break;
    
    int i=0;
    for (i=0; i<r_size; i++)
      scanf("%d", &r[i]);
    
    for (i=0; i<b_size; i++)
      scanf("%d", &b[i]);

    int ans = INF;
    for (i=0; i<r_size; i++){
      int aux = solve(b_size, r_size);
      ans = min(aux, ans);
      shifta(r_size);
      
    }
    printf("%d\n", 0-ans);
  }

  return 0;
}
