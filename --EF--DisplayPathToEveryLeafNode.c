#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
void displayPath(bt *root, int arr[], int n){
    if(root == NULL)
        return;
    arr[n] = root->data;
    n++;
    displayPath(root->left,arr,n);
    displayPath(root->right,arr,n);
    if(root->left == NULL && root->right == NULL){
        for(int i = 0;i<n;i++)
            printf("%d ",arr[i]);
        printf("\n");
    }
}
int main(){
    int arr[100];
    bt *root = constructbt();
    displayPath(root,arr,0);
    return 0;
}