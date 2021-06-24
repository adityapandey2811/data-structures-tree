#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int *getPath(bt *root, int n, int *arr, int *res){
    if(root == NULL)
        return arr;
    if(*res != 1){
        *arr = root->data;
        arr++;
    }
    if(root->data == n){
        *res = 1;
        return arr;
    }
    if(*res != 1){
        getPath(root->left,n,arr,res);
        getPath(root->right,n,arr,res);
    }
}
int main(){
    int a[100],b[100];
    int *arr1, *arr2, res, i = 0;
    bt *root1 = constructbt();
    arr1 = a;
    arr2 = b;
    getPath(root1,11,arr1,&res);
    res = 0;
    getPath(root1,19,arr2,&res);
    while(a[i] == b[i]){
        i++;
    }
    printf("%d\n",a[i-1]);
    return 0;
}