#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int arr1[100], arr2[100], ml = INT_MAX ,mr = INT_MIN;
void verticalSum(bt *root, int *res){
    int l = *res, r = *res;
    l--;
    r++;
    if(root == NULL){
        return;
    }
    if(*res >= 0){
        arr1[*res] += root->data;
    }
    if(*res < 0){
        arr2[(*res*(-1))-1] += root->data;
    }
    if(ml>l)
        ml = l;
    if(mr<r)
    mr = r;
    verticalSum(root->left,&l);
    verticalSum(root->right,&r);
}
int main(){
    bt *root = constructbt();
    int res = 0, i = 0, j, k;
    verticalSum(root,&res);
    j = ml; k = mr;
    for(i = (ml+2)*(-1); i >= 0; i--)
        printf("%d ",arr2[i]);
    for(i = 0; i < mr; i++)
        printf("%d ",arr1[i]);
}