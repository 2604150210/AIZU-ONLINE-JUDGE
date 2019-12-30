#include<bits/stdc++.h>
using namespace std;
struct Node{
  string name;
  int time, over, id;
  bool operator<(const Node& that)const{
    return over < that.over;
  }
};
int main(){
  int n, q;
  cin >> n >> q;
  vector<Node>v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i].name >> v[i].time;
    v[i].id = i;
  }
  deque<Node>D(v.begin(), v.end());
  int cur = 0;
  while(D.size()){
    Node head = D.front();
    if(head.time <= q){
      cur += head.time;
      v[head.id].over = cur;
    }else{
      head.time -= q;
      cur += q;
      D.push_back(head);
    }
    D.pop_front();
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < n; i++){
    cout << v[i].name << " " << v[i].over << endl;
  }
}