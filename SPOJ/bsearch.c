#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int bsearch1 (int arr[100000], int num, int l, int r){
	
	int m = (l+r)/2;

//	printf ("%d %d\n", l, r);

	if (l > r)
		return -1;

	if (l == r && arr[l] != num)
		return -1;
	
	if (l == r && arr[l] == num)
		return l;
	
	if (arr[m] < num)
		return bsearch1 (arr, num, m+1, r);
	else
		return bsearch1 (arr, num, l, m);
}

int main (){

	int arr[100000];
	int n, p;
	
	scanf ("%d%d", &n, &p);

	int i;

	for (i = 0; i < n; i++)
		scanf ("%d", &arr[i]);

	int num;
	for (i = 0; i < p; i++){
		scanf ("%d", &num);
		printf ("%d\n", bsearch1 (arr, num, 0, n-1));
	}

	return 0;
}
