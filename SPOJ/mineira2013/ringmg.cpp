#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
	
	int n;

	while (true){
		cin >> n;

		if (n == 0) break;

		int a = -1;
		int b = -1;

		vector<int> posto (2*n);
		vector<int> dist (2*n);

		for (int i=0; i<n; i++){
			cin >> posto[i];
			posto[i+n] = posto[i];
		}

		for (int i=0; i<n; i++){
			cin >> dist[i];
			dist[i+n] = dist[i];
		}
	
		for (int i=0; i<n; i++){
		 	bool valid = true;
			int gasosa = posto[i];
			for (int j=i; j<=i+n; j++){
				if (gasosa < dist[j]){
					valid = false;
					break;
				}

				gasosa = gasosa - dist[j] + posto[(j+1)%n];
			}

			if (valid){
				a = i+1;
				//cout << "foi: " << i+1 << endl;
				break;
			}
		}
	
		for (int i=n; i<2*n; i++){
			bool valid = true;
			int gasosa = posto[i];
			//cout << "comecou: " << gasosa << endl;
			for (int j=i; j>=i-n; j--){
				if (gasosa < dist[(j-1+n)%n]){
					//cout << "deu pau: " << dist[(j-1+n)%n] << endl;
					valid = false;
					break;
				}

				gasosa = gasosa - dist[(j-1+n)%n] + posto[(j-1+n)%n];

				//cout << "vrum: " << gasosa << endl;
			}

			if (valid){
				b = i-n+1;
				//cout << "foi denovo: " << i-n+1 << endl;
				break;
			}

		}


		cout << a << ' ' << b << endl;
		

	}

	return 0;
}

