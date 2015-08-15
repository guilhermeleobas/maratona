//http://community.topcoder.com/stat?c=problem_statement&pm=10587

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class TriFibonacci{
public:
	int complete(vector<int> A){
		int valor;
		
		if (A[0] == -1){
			A[0] = A[3] - A[2] - A[1];
			valor = A[0];
		}
		else if (A[1] == -1){
			A[1] = A[3] - A[2] - A[0];
			valor = A[1];
		}
		else if (A[2] == -1){
			A[2] = A[3] - A[1] - A[0];
			valor = A[2];
		}
		else {
			for (int cont=3; cont<A.size(); cont++){
				if (A[cont] == -1){
					A[cont] = A[cont-1] + A[cont-2] + A[cont-3];
					valor = A[cont];
				}
				else {
					if (A[cont] != A[cont-1] + A[cont-2] + A[cont-3]){
						valor = -1;
						return valor;
					}
				}
			}
		}

		if (valor < 1) valor = -1;

		return valor;
	}

};
