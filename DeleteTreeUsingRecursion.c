#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
void deleteTreeR(bt **root){
    if((*root) == NULL)
        return;
    deleteTreeR(&(*root)->left);
    deleteTreeR(&(*root)->right);
    free((*root));
    (*root) = NULL;
}
int main(){
    bt *root = constructbt();
    displayL(root);
    printf("\n");
    deleteTreeR(&root);
    displayL(root);
    return 0;
}