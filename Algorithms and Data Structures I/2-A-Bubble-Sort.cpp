#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int cnt= 0;
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n-1-i; j++){
      if(a[j] > a[j+1]){
        cnt ++;
        swap(a[j+1], a[j]);
      }
    }
  }
  for(int i = 0; i < n; i++){
    if(i)cout << ' ';
    cout << a[i];
  }
  cout << endl;
  cout << cnt << endl;
}