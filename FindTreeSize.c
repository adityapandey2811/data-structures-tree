#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int findTreeSize(bt *root){
    if(root == NULL)
        return 0;
    else return(findTreeSize(root->left)+findTreeSize(root->right)+1);
}
int main(){
    bt *root = constructbt();
    int n = findTreeSize(root);
    printf("%d\n",n);
    return 0;
}