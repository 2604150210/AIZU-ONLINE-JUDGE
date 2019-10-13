//
// Created by jal on 2019-10-09.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 100010, INIT_VALUE = INT_MAX;
vector<int>a(N);
struct Tree{
    int Min;
    int left, right;
};
vector<Tree>nodes(4*N);
int getMin(int root, int left, int right){
    if(left <= nodes[root].left and right >= nodes[root].right){
        return nodes[root].Min;
    }
    int mid = (nodes[root].left + nodes[root].right) >> 1;
    if(right <= mid){
        return getMin(2*root, left, right);
    }
    if(left > mid){
        return getMin(2*root+1, left, right);
    }
    return min(getMin(2*root, left, mid), getMin(2*root+1, mid+1, right));
}
void update(int root, int index, int x){
    if(nodes[root].left == nodes[root].right){
        nodes[root].Min = x;
        return;
    }
    int mid = (nodes[root].left + nodes[root].right) >> 1;
    if(index <= mid){
        update(2*root, index, x);
    }
    else{
        update(2*root+1, index, x);
    }
    nodes[root].Min = min(nodes[root*2].Min, nodes[root*2+1].Min);
}
void createTree(int root, int left, int right){
    nodes[root].left = left;
    nodes[root].right = right;
    if(left == right){
        nodes[root].Min = INIT_VALUE;
        return;
    }
    int mid = (left + right) >> 1;
    createTree(root*2, left, mid);
    createTree(root*2+1, mid+1, right);
    nodes[root].Min = min(nodes[root*2].Min, nodes[root*2+1].Min);
}
int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    createTree(1, 0, n-1);
    for(int i = 0; i < q; i++){
        int com;
        scanf("%d", &com);
        if(com == 1){// find(s, t)
            int s, t;
            scanf("%d %d", &s, &t);
            cout << getMin(1, s, t) << endl;
        }
        else{// update(index, x)
            int index, x;
            scanf("%d %d", &index, &x);
            update(1, index, x);
        }
    }
    return 0;
}
