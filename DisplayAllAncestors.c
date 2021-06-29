#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
void displayAncestors(bt *root, int n, int *res){
    if(root == NULL)
        return;
    if(root->data == n){
        *res = 1;
        printf("%d ",root->data);
        return;
    }
    if(*res != 1)
        displayAncestors(root->left,n,res);
    if(*res != 1)
        displayAncestors(root->right,n,res);
    if(*res == 1)
        printf("%d ",root->data);
}
int main(){
    int res = 0;
    bt *root = constructbt();
    displayAncestors(root,10,&res);
    return 0;
}