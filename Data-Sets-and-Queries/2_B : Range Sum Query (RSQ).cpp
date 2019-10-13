//
// Created by jal on 2019-10-13.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 100010, INIT_VALUE = 0;
struct Tree{
    int sum;
    int left, right;
};
vector<Tree>nodes(4*N);
int getSum(int root, int left, int right){
    if(left <= nodes[root].left and right >= nodes[root].right){
        return nodes[root].sum;
    }
    int mid = (nodes[root].left + nodes[root].right) >> 1;
    if(right <= mid){
        return getSum(2*root, left, right);
    }
    if(left > mid){
        return getSum(2*root+1, left, right);
    }
    return getSum(2*root, left, mid) + getSum(2*root+1, mid+1, right);
}
void update(int root, int index, int x){
    if(nodes[root].left == nodes[root].right){
        nodes[root].sum += x;
        return;
    }
    int mid = (nodes[root].left + nodes[root].right) >> 1;
    if(index <= mid){
        update(2*root, index, x);
    }
    else{
        update(2*root+1, index, x);
    }
    nodes[root].sum = nodes[root*2].sum + nodes[root*2+1].sum;
}
void createTree(int root, int left, int right){
    nodes[root].left = left;
    nodes[root].right = right;
    if(left == right){
        nodes[root].sum = INIT_VALUE;
        return;
    }
    int mid = (left + right) >> 1;
    createTree(root*2, left, mid);
    createTree(root*2+1, mid+1, right);
    nodes[root].sum = nodes[root*2].sum + nodes[root*2+1].sum;
}
int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    createTree(1, 1, n);
    for(int i = 0; i < q; i++){
        int com;
        scanf("%d", &com);
        if(com == 1){// getSum(s, t)
            int s, t;
            scanf("%d %d", &s, &t);
            cout << getSum(1, s, t) << endl;
        }
        else{// update(index, x)
            int index, x;
            scanf("%d %d", &index, &x);
            update(1, index, x);
        }
    }
    return 0;
}
