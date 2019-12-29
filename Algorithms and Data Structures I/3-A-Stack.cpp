#include<bits/stdc++.h>
using namespace std;

int main(){
  string x;
  stack<string>S;
  string O = "+-*/";
  while(cin >> x){
    if(S.empty()){
      S.push(x);
      continue;
    }
    if(O.find(x[0]) != string::npos){
      int b = stoi(S.top());
      S.pop();
      int a = stoi(S.top());
      S.pop();
      int c;
      switch (x[0])
      {
      case '+':
        c = a + b;
        break;
      
      case '-':
        c = a - b;
        break;
      
      case '*':
        c = a * b;
        break;
      
      case '/':
        c = a / b;
        break;
      
      default:
        break;
      }
      S.push(to_string(c));
    }else{
      S.push(x);
    }
  }
  cout << S.top() << endl;
}