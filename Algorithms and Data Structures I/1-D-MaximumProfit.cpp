#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int x;
  int maximum = INT_MIN, minimum = INT_MAX;
  for(int i = 0; i < n; i++){
    cin >> x;
    maximum = max(maximum, x - minimum);
    minimum = min(minimum, x);
  }
  cout << maximum << endl;
}