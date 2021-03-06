//Structure Type
typedef struct genericTree{
    int data;
    struct genericTree *nextSibling, *firstChild;
}gentre;

//Calculation of number of children for that node
int noOfSiblings(gentre *root){
    int i = 0;
    root = root->firstChild;
    while(root != NULL){
        root = root->nextSibling;
        i++;
    }
    return i;
}