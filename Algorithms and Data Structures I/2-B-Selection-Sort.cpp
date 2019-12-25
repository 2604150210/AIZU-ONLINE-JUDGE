#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int cnt = 0;
  for(int i = 0; i < n-1; i++){
    int p = i;
    for(int j = i; j < n; j++){
      if(a[j] < a[p]){
        p = j;
      }
    }
    if(p != i){
      swap(a[p], a[i]);
      cnt++;
    }
  }
  for(int k = 0; k < n; k++){
    if(k)cout << ' ';
    cout << a[k];
  }
  cout << endl;
  cout << cnt << endl;
}