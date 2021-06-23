#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
void checkPath(bt *root, int checkSum, int currentSum, int *res){
    if(root == NULL)
        return;
    currentSum += root->data;
    if(currentSum == checkSum){
        *res = 1;
        return;
    }
    checkPath(root->left,checkSum,currentSum,res);
    checkPath(root->right,checkSum,currentSum,res);
}
int main(){
    int res = 0;
    bt *root = constructbt();
    checkPath(root,10,0,&res);
    (res==1)?(printf("Yes\n")):(printf("No\n"));
    return 0;
}