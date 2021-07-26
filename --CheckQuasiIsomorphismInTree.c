#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
int checkQuasiIsomorphic(bt *root1, bt *root2){
    if(root1 == NULL && root2 == NULL)
        return 1;
    if((root1 && !root2) ||(!root1 && root2))
        return 0;
    return ((checkQuasiIsomorphic(root1->left,root2->left) && checkQuasiIsomorphic(root1->right,root2->right)) || (checkQuasiIsomorphic(root1->left,root2->right) && checkQuasiIsomorphic(root1->right,root2->left)));
}
int main(){
    bt *root1 = constructbt(), *root2 = constructbt();
    int i = checkQuasiIsomorphic(root1,root2);
    if(i == 1)
        printf("Quasi-Isomorphic\n");
    else
        printf("Not Quasi-Isomorphic\n");
    return 0;
}