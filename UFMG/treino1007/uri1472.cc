#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool bsearch (const vector<int> &v, int number){
  int l = 0, r = v.size();
  // [l, r)
  
  //cout << "procurando por=" << number << endl;
  while (r - l > 1){
    int mid = (r + l)/2;
    
    //cout << "intervalos= " << l << ' ' << mid << ' ' << r << endl;
    //cout << v[mid] << ' ' << number << endl;
    if (v[mid] == number) l = mid;
    else if (v[mid] > number) r = mid;
    else l = mid+1;
  }
  
  return v[l] == number;
}

int main (){
	
  while (true){
    int n;
    cin >> n;
    if (not cin) break;
    
    vector<int> v (n);
    
    for (int i=0; i<n; i++){
      cin >> v[i];
    }

    for (int i=1; i<n; i++)
      v[i] += v[i-1];

    int k = v.back()/3;

    int ans = 0;

    for (int i=0; i<n; i++){
      int aux = 0;
      aux += bsearch (v, v[i]);
      aux += bsearch (v, v[i]+k);
      aux += bsearch (v, v[i]+2*k);
      if (aux == 3)
        ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
