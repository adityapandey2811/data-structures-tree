#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
bt* closestKey(bt *root, int key){
    bt *temp = NULL;
    if(root == NULL)
        return root;
    if(key == root->data)
        return root;
    if(key>root->data){
        if(!root->right)
            return root;
        temp = closestKey(root->right,key);
        return (abs(temp->data-key) > abs(root->data-key))?(root):(temp);
    }
    else{
        if(!root->left)
            return root;
        temp = closestKey(root->left,key);
        return (abs(temp->data-key) > abs(root->data-key))?(root):(temp);
    }
    return NULL;
}
int main(){
    bt *root = constructbt();
    printf("%d",closestKey(root,4)->data);
    return 0;
}
