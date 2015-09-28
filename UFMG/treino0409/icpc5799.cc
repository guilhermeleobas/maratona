#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_set (int a, int b, int c){
  if (a == b and a == c)
    return true;
  return false;
}

bool is_pair (int a, int b, int c){
  if (a == b or a == c or b == c)
    return true;
  return false;
}

class cards {

 public:
  bool s, p;
  int x, y;
  int a, b, c;
  cards (int a, int b, int c){
    s = false;
    p = false;
    this->a = a, this->b = b, this->c = c;
    if (is_set (a, b, c)){
      s = true;
      x = a, y = a;
    }
    else {
      p = true;
      if (a == b){
        x = a;
        y = c;
      }
      else if (a == c){
        x = a;
        y = b;
      }
      else {
        x = b;
        y = a;
      }
    }
  }
};
bool operator < (const cards& v, const cards& other){
    if (v.s){
      if (other.s){
        // both are sets
        return v.x < other.x;
      }
      return false;
    }
    else {
      if (other.s) return true;
      // both are pairs;
      // compare pairs using the rules in the problem.
      if (v.x == other.x){
        return v.y < other.y;
      }
      else {
        return v.x < other.x;
      }
    }
  }

vector<cards> gen (){
  
  vector<cards> v;
  for (int i=1; i<=13; i++){
    for (int j=1; j<=i; j++){
      for (int k=1; k<=j; k++){
        if (is_set (i, j, k) or is_pair (i, j, k)){
          vector<int> aux (3);
          aux[0]=i, aux[1]=j, aux[2]=k;
          sort (aux.begin(), aux.end());
          v.push_back (cards (aux[0], aux[1], aux[2]));
        }
      }
    }
  }
  
  sort (v.begin(), v.end());
  
  
  return v;
}

int main (){
  
  vector<cards> v = gen ();
  
  while (true){
    int a, b, c;
    cin >> a >> b >> c;
    
    if (a == 0 and b == 0 and c == 0) break;
    
    cards my_card (a, b, c);
    
    if (not is_set (a, b, c) and not is_pair (a, b, c)){
      cout << v[0].a << ' ' << v[0].b << ' ' << v[0].c << endl;
      continue;
    }
    
    bool valid = false;
    for (int i=0; i<v.size()-1; i++){
      if (my_card.x == v[i].x and my_card.y == v[i].y){
        valid = true;
        vector<int> aux (3);
        cout << v[i+1].a << ' ' << v[i+1].b << ' ' << v[i+1].c << endl;
      }
    }
    
    if (not valid)
      cout << '*' << endl;
    
  }
  return 0;
}
