#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

class BigInt {

private:
	string number;
	bool sign;

	/* 	
		+ => True;
		- => False;
	*/

	string IteratorToString (string::iterator, string::iterator);
	pair<string, bool> split (string);

	string Sum (BigInt, BigInt);
	string Sub (BigInt, BigInt);
	string Mul (BigInt, BigInt);
	string Div (BigInt, BigInt);
	string ShiftLeft (BigInt);
	bool Less (BigInt, BigInt);
	bool Greater (BigInt, BigInt);
	bool Greater (BigInt, int);
	bool Equals (BigInt, BigInt);
	bool Diff (BigInt, BigInt);


public:

	BigInt ();
	BigInt (const string);
	BigInt (const string, bool value);
	BigInt (int);
	BigInt (int, const string);

	void setNumber (const string);
	void setNumber (string::iterator begin, string::iterator end);
	void setSign (const bool sign);
	void setSign (const char);
	string getNumber() const;
	bool getSign () const;

	int size ();
	void fixLength (string&, string&);
	void add (string);

	char operator [] (int);
	void operator = (string);
	void operator = (int);
	BigInt operator + (BigInt);
	BigInt operator + (int);
	BigInt operator - (BigInt);
	BigInt operator * (BigInt);
	BigInt operator * (int);
	BigInt operator / (BigInt);
	BigInt operator >> (int);
	void operator << (int);
	bool operator < (BigInt);
	bool operator <= (BigInt);
	bool operator > (BigInt);
	bool operator > (int);
	bool operator >= (BigInt);
	bool operator == (BigInt);
	bool operator != (BigInt);
};

typedef BigInt bigint;

inline std::ostream& operator << (ostream &stream, BigInt const &B){

	if (!B.getSign()){
		stream << '-';
	}
	stream << B.getNumber();

	return stream;
}


inline std::istream& operator >> (istream &stream, BigInt &B){
	string s;
	stream >> s;

	BigInt aux (s);

	B = aux;

	return stream;
}

string BigInt::IteratorToString (string::iterator begin, string::iterator end){
	string result;

	while (begin != end){
		result += *begin;
		begin++;
	}
	return result;
}

pair<string, bool> BigInt::split (string number){
	if (number[0]-'0' < 0 || number[0]-'0' > 9){
		if (number[0] == '-')
			return make_pair ( IteratorToString ( number.begin()+1, number.end() ), false);
		else if (number[0] == '+')
			return make_pair ( IteratorToString (number.begin()+1, number.end() ), true);
		else
			abort();
	}
	else {
		return make_pair (number, true);
	}
}

BigInt::BigInt (){
	this->number = "0";
	this->sign = true;
}

BigInt::BigInt (const string number){
	pair<string, bool> var = split (number);

	this->number = var.first;
	this->sign = var.second;
}

BigInt::BigInt (const string number, bool sign){
	this->sign = sign;
	this->number = number;
}

BigInt::BigInt (int len, const string number){
	this->sign = true;
	for (int i=0; i<len; i++)
		this->number += number;
}

BigInt::BigInt (int number){

	if (number < 0)
		this->sign = false;
	else
		this->sign = true;

	if (number < 0)
		number *= -1;

	this->number = to_string (number);
}

void BigInt::setNumber (const string number){
	this->number = number;
}

void BigInt::setNumber (string::iterator begin, string::iterator end){
	
	// Call IteratorToString;
	this->number = IteratorToString (begin, end);
	
}

void BigInt::setSign (const bool sign){
	this->sign = sign;
}

void BigInt::setSign (const char sign){

	if (sign == '+')
		this->sign = true;
	else
		this->sign = false;
}

string BigInt::getNumber() const{
	return this->number;
}

bool BigInt::getSign () const{
	return this->sign;
}

int BigInt::size (){
	return this->number.size();
}

//--------------------------------------------------------------------------------

void BigInt::fixLength (string &N, string &M){
	
	if ( M.size() > N.size())
		swap (N, M);

	int diff = abs ( (int) M.size() - (int) N.size() );

	if ( M.size() < N.size())
		M.insert (0, diff, '0');
		
}

//--------------------------------------------------------------------------------
// Overloads;

char BigInt::operator [] (int pos){
	return this->number[pos];
}

void BigInt::operator = (string s){
	this->setNumber (s);
}

void BigInt::operator = (int n){
	this->setNumber ( to_string (n) );
}


BigInt BigInt::operator + (BigInt M){
	
	BigInt ans;

	if (this->getSign() == M.getSign()){
		ans.setNumber (Sum (*this, M));
		ans.setSign (this->getSign());
	}
	else {
		// Different sign operators. Call Sub;

		// Solve sign difference;
		if (*this > M){
			ans.setNumber ( Sub (getNumber(), M.getNumber()) );
			ans.setSign (this->getSign());
		}
		else{
			ans.setNumber ( Sub (M.getNumber(), getNumber()) );
			ans.setSign (M.getSign());
		}
	}

	if (ans.getNumber() == "0")
		ans.setSign ('+');

	return ans;
}

BigInt BigInt::operator + (int n){
	
	BigInt M (n);

	return (*this + M);
}

// ---------------------------------------------------------------------------

BigInt BigInt::operator - (BigInt M){

	BigInt ans;

	M.setSign (!M.getSign());
	return *this + M;

	/*
	1. (+)-(+) will result in (+)+(-)
	2. (-)-(-) will result in (-)+(+)
	3. (+)-(-) will result in (+)+(+)
	4. (-)-(+) will result in -[(+)+(+)]
	*/

	return ans;
}

BigInt BigInt::operator * (BigInt M){

	BigInt ans;

	ans.setNumber( Mul (*this, M));
	
	ans.setSign (!(this->getSign()^M.getSign()));
	
	return ans;
}

BigInt BigInt::operator * (int n){
	
	BigInt M (n);

	return *this * M;
}

BigInt BigInt::operator / (BigInt M){

	BigInt ans;

	ans.setNumber ( Div (*this, M));
	ans.setSign (!(this->getSign()^M.getSign()));
	
	return ans;
}

BigInt BigInt::operator >> (int offset){

	// Shift-Left is implemented dividing the number by 10 and not by 2 as usual.
	BigInt ans (ShiftLeft (*this));

	return ans;
}

void BigInt::operator << (int offset){

}

// -----------------------------------------------------------------------

bool BigInt::operator < (BigInt M){
	
	// Call BigInt::Less
	return Less (*this, M);

}

bool BigInt::operator <= (BigInt M){

	return Less (*this, M) || Equals (*this, M);
}

bool BigInt::operator > (BigInt M){
	
	return Greater (*this, M);
}

bool BigInt::operator > (int M){
	
	return Greater (*this, M);
}

bool BigInt::operator >= (BigInt M){
	
	return Greater (*this, M) || Equals (*this, M);
}

bool BigInt::operator == (BigInt M){
	
	return Equals (*this, M);
}

bool BigInt::operator != (BigInt M){
	
	return Diff (*this, M);
}
//---------------------------------------------------------------------------------

string BigInt::Sum (BigInt N, BigInt M){
	
	bool carryIn = false, carryOut = false;
	int integer, b, s;
	string result, A = N.getNumber(), B = M.getNumber();

	fixLength (A, B);
	
	result.resize (A.size(), '0');

	for (int i = A.size()-1; i >= 0; i--){
		
		integer = (int)A[i]-'0' + (int)B[i]-'0';

		if (integer+carryIn >= 10){
			result[i] = (char)(integer+carryIn-10)+'0';
			carryOut = true;
		}
		else {
			result[i] = (char)(integer+carryIn)+'0';
			carryOut = false;
		}

		carryIn = carryOut;
	}

	if (carryOut){
		result.insert (0, 1, '1');
	}

	return result;
}

string BigInt::Sub (BigInt N, BigInt M){
	
	int integer = 0;
	bool carryIn = false, carryOut = false;
	string result, A = N.getNumber(), B = M.getNumber();

	fixLength (A, B);

	if (N < M)
		swap (A, B);

	result.resize (A.size(), '0');

	for (int i=A.size()-1; i>= 0; i--){
		carryIn = carryOut;
		integer = ((int)A[i]-'0') - ((int)B[i]-'0');

		if (carryIn)
			integer -= 1;

		integer < 0 ? carryOut = true : carryOut = false;

		result[i] = (char)(integer+10*carryOut)+'0';
	}

	while (result[0] == '0' && result.size() > 1)
		result.erase (result.begin());

	return result;
}

string BigInt::Mul (BigInt N, BigInt M){

	string A = N.getNumber(), B = M.getNumber();
	BigInt result;
	int carryIn = 0, carryOut = 0, offset = 0;

	if (N < M)
		swap (A, B);

	for (int i = B.size()-1; i >= 0; i--){
		carryOut = 0;
		string aux (A.size(), '0');
		for (int j = A.size()-1; j >= 0; j--){
			carryIn = carryOut;
			int integer = ((int)A[j]-'0') * ((int)B[i]-'0');
			integer += carryIn;
			carryOut = integer/10;
			aux[j] = (char)(integer%10)+'0';
		}

		if (carryOut)
			aux.insert (0, 1, (char)(carryOut)+'0');
		
		aux.append (offset++, '0');

		BigInt t (aux);
		result = result + t;
	}

	return result.getNumber();
}

string BigInt::Div (BigInt N, BigInt M){
	
	// Div is implemented using multiplication and Binary search algorithms;
	BigInt low = 0, high = N;

	while (true){
		BigInt mid = (low + high) >> 1;

		if ( (low+1)*M > N ) return low.getNumber();
		else if (mid*M > N)  high = mid;
		else low = mid;
	}

	return low.getNumber();
}

//---------------------------------------------------------------------------

string BigInt::ShiftLeft (BigInt N){

	// It's possible to implement a shift left for decimal numbers without divide '/' operator;
	// x >> 1 is the same as remove the last number and multiply the rest by 5.

	string A = N.getNumber();

	BigInt M (5);
	int decimal = (int)A.back()-'0';
	A.erase (A.begin() + A.size()-1);

	N = A;
	BigInt ans = N*M + (decimal*5)/10;

	return ans.getNumber();
}

//---------------------------------------------------------------------------

bool BigInt::Equals (BigInt N, BigInt M){
	
	if (N.size() != M.size())
		return false;

	for (int i=0; i<N.size(); i++){
		if (N[i] != M[i])
			return false;
	}

	return true;
}

bool BigInt::Diff (BigInt N, BigInt M){
	
	// Call BigInt::Equals();

	if (!Equals (N, M))
		return true;

	return false;
}

bool BigInt::Less (BigInt N, BigInt M){
	
	if (N.size() < M.size())
		return true;
	
	if (N.size() > M.size())
		return false;

	for (int i=0; i<N.size(); i++){
		if (N[i] == M[i])
			continue;

		if (N[i] < M[i])
			return true;
	}

	return false;
}

bool BigInt::Greater (BigInt N, BigInt M){
	
	if (N.size() < M.size())
		return false;

	if (N.size() > M.size())
		return true;

	for (int i = 0; i < N.size(); i++){
		if (N[i] > M[i])
			return true;

		if (N[i] < M[i])
			return false;
	}

	return false;
}

bool BigInt::Greater (BigInt N, int m){
	BigInt M (m);

	return Greater (N, M);
}

int main (){

	vector<bigint> fib;

	fib.push_back (0);
	fib.push_back (1);

	for (int i=2; i<=5000; i++)
		fib.push_back (fib[i-1] + fib[i-2]);

	while (true){
		int n;
		cin >> n;

		if (not cin) break;

		cout << "The Fibonacci number for " << n << " is " << fib[n] << endl;
	}
	return 0;
}