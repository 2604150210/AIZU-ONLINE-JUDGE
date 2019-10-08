//
// Created by jal on 2019-10-08.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 10001, Q = 100001;
int F[N];
int getF(int x){
    return x != F[x]? F[x] = getF(F[x]): F[x];
}
int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++){
        F[i] = i;
    }
    for(int i = 0; i < q; i++){
        int com, x, y;
        scanf("%d %d %d", &com, &x, &y);
        int fx = getF(x);
        int fy = getF(y);
        if(com == 0){
            F[fx] = fy;
        }else{
            printf("%d\n", fx == fy);
        }
    }
    return 0;
}