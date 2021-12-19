#include<stdio.h>
#include<stdlib.h>
long int catalan(int n, int k){
    long int i,res = 1;
    for(i=0;i<k;i++){
        res *= n-i;
        res /= i+1;
    }
    return res;
}
long int nBst(int n){
    return catalan(2*n,n)/(n+1);
}
int main(){
    printf("%ld\n",nBst(12));
    return 0;
}
