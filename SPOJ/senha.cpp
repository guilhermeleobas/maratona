#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef struct {
	int letters[7];
	deque<pair<int, int> > numbers;
	int a;
} password;

void imprime (password *senha, int n){

	for (int i=0; i<n; i++){

		for (int cont=0; cont<5; cont++){
			cout << senha[i].numbers[cont].first << ' ' << senha[i].numbers[cont].second << ' ';
		}

		for (int cont=0; cont<6; cont++){
			cout << senha[i].letters[cont] << ' ';
		}
		cout << endl;

	}	

}

void imprime_vec (vector<int> v){
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << ' ';
	}
	cout << endl;
}

int unlock (password *senha, int n, int posicao){
	vector<int> v;
	v.resize (10, 0);
	int i;
	int max;

	for (int cont=0; cont<n; cont++){
		i = senha[cont].letters[posicao];
		v[senha[cont].numbers[i].first]++;
		v[senha[cont].numbers[i].second]++;
	}

	//imprime_vec(v);

	max = 0;
	for (int cont=1; cont<10; cont++){
		if (v[max] < v[cont]){
			max = cont;
		}
	}
	//cout << max << endl;
	return max;
}


int main(){
	
	int n;
	int a, b;
	char c;
	int aux;
	int t;
	pair<int, int> comb;
	password *senha;
	vector<int> result;	

	t = 1;

	while (true){
		cin >> n;
		if (n == 0) break;

		senha = new password[n];

		for (int i=0; i<n; i++){

			for (int cont=0; cont<5; cont++){
				cin >> a >> b;
				if (a > b){
					aux = a;
					a = b;
					b = aux;
				}
				comb = make_pair (a, b);
				senha[i].numbers.push_back (comb);
			}

			for (int cont=0; cont<6; cont++){
				cin >> c;
				senha[i].letters[cont] = c-65;
			}

		}

		for (int cont=0; cont<6; cont++){
			result.push_back(unlock (senha, n, cont));
		}

		cout << "Teste " << t++ << endl; 
		imprime_vec (result);
		cout << endl;
		//unlock (senha, n);
		//imprime (senha, n);
		
		result.clear();

		delete [] senha;
	}






	return 0;
}