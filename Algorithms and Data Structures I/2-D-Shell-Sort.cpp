#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
void Print(vector<int>m){
  for(int i = 0; i < m.size(); i++){
    if(i)cout << ' ';
    cout << m[i];
  }
  cout << endl;
}
void InsertSort(vector<int>&a, int step){
  for(int i = step; i < a.size(); i++){
    int k = a[i], j = i-step;
    while(j >= 0 and a[j] > k){
      a[j+step] = a[j];
      j -= step;
      cnt++;
    }
    a[j+step] = k;
  }
}
int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int>m;
  int x = n;
  if(x == 1){
    m.push_back(1);
  }else{
    while(x > 1){
      m.push_back(x / 2);
      x /= 2;
    }
  }
  for(auto step: m){
    InsertSort(a, step);
  }

  cout << m.size() << endl;

  Print(m);

  cout << cnt << endl;

  for(auto i: a){
    cout << i << endl;
  }
}