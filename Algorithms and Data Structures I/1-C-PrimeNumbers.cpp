#include<bits/stdc++.h>
using namespace std;
bool prime(int n){
  if(n == 2)return true;
  if(n <=1 or n % 2 == 0)return false;
  for(int i = 3; i * i <= n; i+=2){
    if(n % i == 0)return false;
  }
  return true;
}
int main(){
  int n;
  cin >> n;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    if(prime(x))cnt ++;
  }
  cout << cnt << endl;
}