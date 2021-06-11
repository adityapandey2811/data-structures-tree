#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int depth(bt *root){
    int l,r;
    if(root == NULL)
        return 0;
    else{
        l = depth(root->left);
        r = depth(root->right);
    }
    if(l>r)
        return l+1;
    else
        return r+1;
}
int main(){
    bt *root = constructbt();
    int n = depth(root);
    printf("Depth: %d\n",n);
    return 0;
}