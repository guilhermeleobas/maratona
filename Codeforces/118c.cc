#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int x = 0;

bool comp (pair<int, int> a, pair<int, int> b){

	int va = abs (a.first - x);
	int vb = abs (b.first - x);

	bool da = a.first > x ? true : false;
	bool db = b.first > x ? true : false;

	if (va != vb)
		return va < vb;

	if (da ^ db)
		return da > db;

	if (da & db)
		return a.second < b.second;

	return a.second > b.second;	
}

void print (vector<pair<int, int> > &v){
	for (int i=0; i<v.size(); i++)
		cout << v[i].first << ' ' << v[i].second << endl;
	cout << endl;
}

pair<int, int> diff (vector<pair<int, int> > v, int k, int i){
	
	x = i;

	sort (v.begin(), v.end(), comp);

	int sum = 0;
	for (int j=0; j<k; j++)
		sum += abs(v[j].first - i);
	
	return make_pair (sum, i);
}

int comp2 (pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int lex (vector<pair<int, int> > &cp, int aux, int temp, int k){
	
	vector<pair<int, int> > a = cp;
	vector<pair<int, int> > b = cp;
	
	x = aux;
	sort (a.begin(), a.end(), comp);
	x = temp;
	sort (b.begin(), b.end(), comp);

	x = aux;

	sort (b.begin(), b.end(), comp);

	for (int i=0; i<k; i++)
		a[i].first = aux;
	for (int i=k; i<a.size(); i++)
		a[i].first = cp[a[i].second].first;

	sort (a.begin(), a.end(), comp2);

	x = temp;

	sort (b.begin(), b.end(), comp);

	for (int i=0; i<k; i++)
		b[i].first = temp;
	for (int i=k; i<b.size(); i++)
		b[i].first = cp[b[i].second].first;

	sort (b.begin(), b.end(), comp2);

	for (int i=0; i<a.size(); i++){
		if (a[i].first == b[i].first) continue;

		if (a[i].first < b[i].first) return aux;
		if (a[i].first > b[i].first) return temp;
	}

	// they are the same vector (a and b);
	return aux;
}

void solver (vector<pair<int, int> > &v, int k){
	
	pair<int, int> aux = diff (v, k, 0);

	vector<pair<int, int> > cp = v;

	for (int i=1; i<10; i++){
		pair<int, int> temp = diff (v, k, i);
		if (aux.first > temp.first)
			aux = temp;
		else if (aux.first == temp.first)
			aux.second = lex (cp, aux.second, temp.second, k);
	}
	
	x = aux.second;

	sort (v.begin(), v.end(), comp);

	for (int i=0; i<k; i++)
		v[i].first = aux.second;
	for (int i=k; i<v.size(); i++)
		v[i].first = cp[v[i].second].first;

	sort (v.begin(), v.end(), comp2);

	cout << aux.first << endl;
	for (int i=0; i<v.size(); i++)
		cout << v[i].first;
	cout << endl;

	//print (v);

	//cout << aux.first << ' ' << aux.second << endl;
}

int main(){
	
	int n, k;
	char c;

	cin >> n >> k;

	vector<pair<int, int> > v (n);

	for (int i=0; i<n; i++){
		cin >> c;
		v[i] = make_pair ((int)c-'0', i);
	}

	solver (v, k);

	return 0;
}
