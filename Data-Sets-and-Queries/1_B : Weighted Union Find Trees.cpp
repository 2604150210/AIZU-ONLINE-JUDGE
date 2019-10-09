//
// Created by jal on 2019-10-08.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int F[N], W[N];
struct Info{
    int father, weight;
    Info(int father, int weight):father(father), weight(weight){}
};
Info getInfo(int x){
    if(x == F[x]){
        return Info(x, 0);
    }
    Info info_x = getInfo(F[x]);
    F[x] = info_x.father;
    W[x] += info_x.weight;
    return Info(F[x], W[x]);
}
void unite(int x, int y, int z){
    Info info_x = getInfo(x), info_y = getInfo(y);
    if(info_x.father == info_y.father)return;
    F[info_y.father] = info_x.father;
    W[info_y.father] = W[x] - W[y] + z;
}
int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++){
        F[i] = i;
    }
    for(int i = 0; i < q; i++){
        int com, x, y, z;
        scanf("%d", &com);
        if(com == 0){
            scanf("%d %d %d", &x, &y, &z);
            unite(x, y, z);
        }else{
            scanf("%d %d", &x, &y);
            Info info_x = getInfo(x), info_y = getInfo(y);
            if(info_x.father == info_y.father){
                printf("%d\n", info_y.weight - info_x.weight);
            }else{
                printf("?\n");
            }
        }
    }
    return 0;
}