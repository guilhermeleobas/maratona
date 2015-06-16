#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main (){
  
  while (true){
    long long A, B;
    cin >> A >> B;
    if (not cin) break;

    string s;
    cin >> s;

    int hb=0, hw=0;
    for (int i=0; i<s.size(); i++){
      if (s[i] == 'W')
        hw++;
      else
        hb++;
    }

    vector<int> w, b;

    for (int i=0; i<hb; i++)
      if (s[i] == 'W')
        w.push_back (i);

    for (int i=s.size()-1; i>=hb; i--)
      if (s[i] == 'B')
        b.push_back (i);


    long long ans = 0;

    int n = b.size();

    for (int i=0; i<n; i++){
      long long x = abs (b[i]-w[i]);
      ans += min (A, (A-B)*(x));
    }
    cout << ans << endl;
  }

  return 0;
}
