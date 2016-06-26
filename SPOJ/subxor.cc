#include <iostream>
#include <vector>

using namespace std;

struct trie{
  int nleft;
  int nright;
  trie* left;
  trie* right;
  
  trie(){
    this->nleft = this->nright = 0;
    this->left = this->right = NULL;
  }
};

void insert (trie* t, int value, int shift){
  bool x = (value >> shift) & 1;
  
  if (shift == -1)
    return;
  
  if (x){
    t->nright += 1;
    if (t->right == NULL)
      t->right = new trie();
    insert (t->right, value, shift-1);
  }
  else{
    t->nleft += 1;
    if (t->left == NULL)
      t->left = new trie();
    insert (t->left , value, shift-1);
  }
}

long long query (trie* t, int k, int value, int shift){
  
  if (shift < 0)
    return 0;
  
  bool x = (value >> shift) & 1;
  bool y = (k >> shift) & 1;
  
  if (t->left == NULL){
    t->left = new trie();
  }
  
  if (t->right == NULL){
    t->right = new trie();
  }
  
  if (y){
    if (!x) return t->nleft + query (t->right, k, value, shift - 1);
    else return t->nright + query (t->left, k, value, shift - 1);
  }
  else {
    if (!x) return query (t->left, k, value, shift-1);
    else return query (t->right, k, value, shift-1);
  }
}


int main (){
  
  int a;
  cin >> a;
  while (a--){
    int n, k;
    cin >> n >> k;
    
    vector<int> v (n);
    
    for (int i=0; i<n; i++){
      cin >> v[i];
    }
    
    int value = 0;
    long long sum = 0;
    trie *t = new trie();
    
    insert (t, 0, 20);
    
    for (auto i: v){
      int aux = value ^ i;
      sum += query (t, k, aux, 20);
      insert (t, aux, 20);
      value = aux; 
    }
    
    cout << sum << '\n';
  }   
}
