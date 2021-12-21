#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int maxDiff(bt *root, int *res){
    int l,r,fin;
    if(root == NULL)
        return INT_MAX;
    if(!root->left && !root->right)
        return root->data;
    l = maxDiff(root->left,res);
    r = maxDiff(root->right,res);
    fin = (l>r)?(r):(l);
    *res = ((root->data-fin) > *res)?(root->data - fin):(*res);
    return (fin > root->data)?(root->data):(fin);
}
int main(){
    int res = INT_MIN;
    bt *root = constructbt();
    maxDiff(root,&res);
    printf("%d\n",res);
    return 0;
}
//8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
//1 8 9 2 -1 6 6 -1 -1 -1 2 -1 9 -1 -1 1 7 -1 -1 -1 -1
