//LCA can also be used to find shortest path between 2 nodes
#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
bt* lcaInBst(bt *root, int a, int b){
    while(1){
        if(root->data < a && root->data < b)
            root = root->right;
        else if(root->data > a && root->data > b)
            root = root->left;
        else
            return root;
    }
}
int main(){
    int res = INT_MIN, a = 48, b = 28; 
    bt *root = constructbt();
    printf("%d\n",lcaInBst(root,a,b)->data);
    return 0;
}
// Input Binary Search Tree for testing 25 20 36 10 22 30 40 5 12 -1 -1 28 -1 38 48 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
