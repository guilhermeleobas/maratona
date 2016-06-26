#include <iostream>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

#define sunday 0
#define monday 1
#define tuesday 2
#define wednesday 3
#define thusday 4
#define friday 5
#define saturday 6


bool leap_year (int year){
  if ((year % 400 == 0) or (year % 4 == 0 and year % 100 != 0))
    return true;
  return false;
}

int main (){
  
  int n;
  cin >> n;
  int day = monday;
  
  map<int, int> mapa;
  for (int year=1000; year<=100100; year++){
    if (leap_year(year))
      day = (day + 2)%7;
    else
      day = (day + 1)%7;
        
    mapa[year] = day;
  }
  
  day = mapa[n];
  for (auto i: mapa){
    if (leap_year(n) != leap_year(i.first))
      continue;
    if (i.second == day and i.first > n){
      cout << i.first << endl;
      break;
    }
  }
  
  return 0;
}
