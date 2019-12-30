#include<bits/stdc++.h>
using namespace std;
int main(){
  const int N = 2000000;
  int a[N];
  int n;
  cin >> n;
  int front = 0, back = 0;
  string o;
  int x;
  for(int i = 0; i < n; i++){
    cin >> o;
    if(o == "insert"){
      cin >> x;
      a[front++] = x;
    }else if(o == "delete"){
      cin >> x;
      for(int j = front-1; j >= back; j--){
        if(a[j] == x){
          int k = j;
          while(k >= back){
            a[k] = a[k-1];
            k--;
          }
          back++;
          break;
        }
      }
    }else if(o == "deleteFirst"){
      if(front > back)front--;
    }else if(o == "deleteLast"){
      if(back < front)back++;
    }
  }
  for(int i = front-1; i >= back; i--){
    cout << a[i];
    if(i == back){
      cout << endl;
    }else{
      cout << ' ';
    }
  }
}