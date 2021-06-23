#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int sum(bt *root){
    if(root == NULL)
        return 0;
    return (root->data + sum(root->left) + sum(root->right));
}
int main(){
    int res = 0;
    bt *root = constructbt();
    res = sum(root);
    printf("%d\n",res);
    return 0;
}