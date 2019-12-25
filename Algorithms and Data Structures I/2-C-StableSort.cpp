#include<bits/stdc++.h>
using namespace std;
struct Node{
  int val;
  char c;
  bool operator==(const Node& a)const{
    return val == a.val && c == a.c;
  }
};
void Print(vector<Node>a){
  for(int i = 0; i < a.size(); i++){
    if(i)cout << ' ';
    cout << a[i].c << a[i].val;
  }
  cout << endl;
}
void BubbleSort(vector<Node>&a){
  for(int i = 0; i < a.size()-1; i++){
    for(int j = 0; j < a.size() - i - 1; j++){
      if(a[j].val > a[j+1].val){
        swap(a[j], a[j+1]);
      }
    }
  }
}
void SelectionSort(vector<Node>&a){
  for(int i = 0; i < a.size() - 1; i++){
    int p = i;
    for(int j = i + 1; j < a.size(); j++){
      if(a[p].val > a[j].val){
        p = j;
      }
    }
    if(p != i){
      swap(a[p], a[i]);
    }
  }
}
int main(){
  int n;
  cin >> n;
  vector<Node>a(n), b(n);
  string s;
  for(int i = 0; i < n; i++){
    cin >> s;
    a[i].c = s[0];
    a[i].val = s[1]-'0';
    b[i] = a[i];
  }
  // Stable Bubble Sort
  BubbleSort(a);
  Print(a);
  cout << "Stable" << endl;
  // NotStable Selection Sort
  SelectionSort(b);
  Print(b);
  if(a == b){
    cout << "Stable" << endl;
  }else{
    cout << "Not stable" << endl;
  }
}