#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

class car{
 public:
  int length, plate, pos;
  car (int plate, int length): length(length), plate (plate), pos(0)
  {}
  car (): length(0), plate(0), pos (0)
  {}
};

bool alloc (vector<int> &field, map<int, car> &info, car c){
  if (info.size() == 0){
    if (field.size() < c.length)
      return false;
    
    field[0] = c.plate;
    c.pos = 0;
    info[c.plate] = c;
    return true;
  }
  else {
    int count = 0;
    int pos = -1;
    for (int i=0; i<field.size(); i++){
      if (field[i] == -1){
        count++;
        if (count == c.length){
          pos = i - count + 1;
          break;
        }
      }
      else {
        int length = info[field[i]].length;
        count = 0;
        i += length - 1;
      }
    }
    
    if (pos == -1)
      return false;
    c.pos = pos;
    field[pos] = c.plate;
    info[c.plate] = c;
    return true;
  }
  
  return false;
}

void rem (vector<int> &field, map<int, car> &info, int p){
  int pos = info[p].pos;
  field[pos] = -1;
  info.erase (p);
}

int main (){
  
  while (true){
    int c, n;
    cin >> c >> n;
    if (not cin) break;
    
    vector<int> field (c, -1);
    map<int, car> info;
    
    int ans=0;
    for (int i=0; i<n; i++){
      char aux;
      cin >> aux;
      if (aux == 'C'){
        int p, q;
        cin >> p >> q;
        bool response = alloc (field, info, car (p, q));
        if (response)
          ans++;
      }
      else {
        int p;
        cin >> p;
        rem (field, info, p);
      }
    }
    
    cout << ans * 10 << endl;
  }
  return 0;
}
