#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int maxPathSum(bt *root, int *res){
    int l,r;
    if(root == NULL)
        return 0;
    l = maxPathSum(root->left,res);
    r = maxPathSum(root->right,res);
    if(*res < l+r+root->data)
        *res = l+r+root->data;
    if(l>=r){
        l += root->data;
        return l;
    }
    else{
        r += root->data;
        return r;
    }
}
int main(){
    int res = 0;
    bt *root = constructbt();
    maxPathSum(root,&res);
    printf("%d\n",res);
    return 0;
}
//1 2 2 3 10 3 10 1 1 -1 -1 -1 -1 7 1 -1 -1 1 1 -1 -1 -1 -1 -1 -1 -1 -1
//1 5 2 10 11 3 11 22 -1 7 -1 -1 -1 -1 -1 4 5 -1 -1 -1 -1 -1 -1
