#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int checkIsomorphic(bt *root1, bt *root2){
    if(root1 == NULL && root2 == NULL)
        return 1;
    if((root1 && !root2) ||(!root1 && root2))
        return 0;
    return (checkIsomorphic(root1->left,root2->left) && checkIsomorphic(root1->right,root2->right));
}
int main(){
    bt *root1 = constructbt(), *root2 = constructbt();
    int i = checkIsomorphic(root1,root2);
    if(i == 1)
        printf("Isomorphic\n");
    else
        printf("Not Isomorphic\n");
    return 0;
}