#include <algorithm>
#include <iostream>
#include <iomanip> 
#include <vector>
#include <string>
#include <map>

using namespace std;

#define sz 26

class trie {
 private:
  map<char, trie*> mapa;
 public:
  trie(){}
  
  void add_word (string word){
    word = word + "$";
    
    trie* t = this;
    for (int i=0; i<word.size(); i++){
      if (t->mapa.find (word[i]) == t->mapa.end()){
        t->mapa[word[i]] = new trie();
      }
      t = t->mapa[word[i]];
    }
  }
  
  int count (const string word){
    int cnt = 1;
    trie* t = this->mapa[word[0]];
    for (int i=1; i<word.size(); i++){
      if (t->mapa.size() > 1){
        cnt++;
      }
      t = t->mapa[word[i]];
    }
    
    return cnt;
  }
  
  void print (trie* t, int level){
    for (map<char, trie*>::iterator it = t->mapa.begin(); it != t->mapa.end(); it++){
      cout << "char: " << it->first << " Level=" << level << endl;
      print (it->second, level+1);
    }
  }
};

int main (){
  
  while (true){
    int n;
    cin >> n;
    if (not cin) break;
    
    trie t;
    vector<string> v;
    for (int i=0; i<n; i++){
      string s;
      cin >> s;
      v.push_back (s);
      t.add_word (s);
    }
   
    int total = 0;
    for (int i=0; i<v.size(); i++){
      total += t.count (v[i]);
    }
    
    cout << fixed << setprecision (2) << (double)total/n << endl;
  }
  return 0;
}
