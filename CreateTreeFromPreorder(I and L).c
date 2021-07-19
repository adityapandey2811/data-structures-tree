#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"btl.h"
bt* constructTree(char *arr, int *k){
    bt *root = NULL;
    int n;
    if(*(arr+(*k)) == '\0')
        return NULL;
    root = (bt*)malloc(sizeof(bt));
    root->left = root->right = NULL;
    root->data = 0;
    if(*(arr+(*k)) == 76){
        root->val = 76;
        k++;
        return root;
    }
    if(*(arr+(*k)) == 73){
        root->val = 73;
    }
    (*k)++;
    root->left = constructTree(arr,k);
    (*k)++;
    root->right = constructTree(arr,k);
    return root;
}
int main(){
    bt *root = NULL;
    int k = 0;
    char *arr = {"IIILLLILILL"};
    root = constructTree(arr, &k);
    preorderc(root);
    return 0;
}