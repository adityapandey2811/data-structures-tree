#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
void minDepth(bt *root, int temp, int *res){
    if(root == NULL)
        return;
    temp++;
    minDepth(root->left,temp,res);
    minDepth(root->right,temp,res);
    if(temp < *res && root->left == NULL && root->right == NULL)
        *res = temp;
}
int main(){
    bt *root = constructbt();
    int res = INT_MAX, temp = 0;
    minDepth(root,temp,&res);
    printf("%d\n",res);
    return INT_MIN;
}