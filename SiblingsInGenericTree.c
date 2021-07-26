//Structure Type
typedef struct genericTree{
    int data;
    struct genericTree *nextSibling, *firstChild;
}gentre;

//Calculation of number of siblings
int noOfSiblings(gentre *root){
    int i = 0;
    while(root != NULL){
        root = root->nextSibling;
        i++;
    }
    return i;
}