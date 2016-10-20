#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

#define mul (6000000000ll + 1)
#define soma (6000000000ll + 2)
#define div (6000000000ll + 3)
#define sub (6000000000ll + 4)
#define invalid (6000000000ll - 100)
#define valid (6000000000ll - 1)
#define divzero (6000000000ll - 10)

#define ll long long

map<char, long long> ops;
map<long long, char> convert;

inline bool is_op(char c){
  return (c == '/')
    or (c == '+')
    or (c == '*')
    or (c == '-');
}

inline bool is_op(long long number){
  return number > 6000000000ll;
}

inline bool is_number(long long number){
  return not is_op(number);
}

ll do_op (ll op, ll n1, ll n2){
  if (op == mul){
    return n1*n2;
  }
  else if (op == soma){
    return n1+n2;
  }
  else if (op == div){
    if (n2 == 0)
      return divzero;
    return floor(n1/n2);
  }
  else if (op == sub){
    return n1-n2;
  }
  else {
    return invalid;
  }
}

long long solve (string& s){
  
  int n = s.size();
  int num = 0, opcode = 0;
  
  bool zero = false;
  stack<ll> pilha;

  for (int i=n-1; i>=0; i-=2){
    if (is_op(s[i])){
      if (pilha.size() < 2)
        return invalid;

      ll op = ops[s[i]];

      ll n2 = pilha.top(); pilha.pop();
      ll n1 = pilha.top(); pilha.pop();

      //cout << s[i] << ' ' << n1 << ' ' << n2 << endl;
      ll aux = do_op (op, n1, n2);

      if (aux == divzero){
        zero = true;
        pilha.push(n1);
      }
      else {
        pilha.push(aux);
      }
    }
    else {
      pilha.push((int)s[i]-48);
    }
  }
  
  if (pilha.size() != 1)
    return invalid;

  if (zero)
    return divzero;
  return pilha.top();

}

/*
long long solve (stack<ll> &s1){
  stack<ll> s2;
  
  bool zero = false;
  
  ll ans = 0;
  
  while (true){
    
    if (s1.size() == 0)
      break;
    ll number = s1.top(); s1.pop();

    if (is_number(number)){
      s2.push(number);
    }
    else {
      ll op = number;
      
      if (s2.size() < 2)
        return invalid;

      ll n2 = s2.top(); s2.pop();
      ll n1 = s2.top(); s2.pop();

      if (not is_number(n1) || not is_number(n2))
        return invalid;
      
      ll aux = do_op(op, n1, n2);
      
      if (aux == divzero){
        zero = true;
        s2.push((long long)(do_op(op, n1, n2+1)));
      }
      else if (aux == invalid)

        return invalid;
      else
        s2.push(aux);
    }
      
  }

  if (s2.size() != 1)
    return invalid;
  if (zero)
    return divzero;

  return s2.top();
}
*/

void print (const vector<string> &v){
  for (int i=0; i<v.size(); i++){
    cout << v[i] << ' ';
  }
  cout << endl;
}

int main (){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  ops['-'] = sub;
  ops['*'] = mul;
  ops['+'] = soma;
  ops['/'] = div;
  
  convert[sub] = '-';
  convert[mul] = '*';
  convert[soma] = '+';
  convert[div] = '/';
  
  while (true){
    //char s[2000000+10];
    //memset (s, '\0', 2000000+10);
    //cin.getline(s, 2000000+10);
    string s;
    getline (cin, s);

    if (not cin)
      break;
    
    ll ans = solve(s);
    if (ans == invalid)
      cout << "Invalid expression.";
    else if (ans == divzero)
      cout << "Division by zero.";
    else
      cout << "The answer is " << ans << ".";
    
    cout << '\n';   
  }
  return 0;
}