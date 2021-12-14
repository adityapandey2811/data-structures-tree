#include<stdio.h>
#include<stdlib.h>
#include"btl.h"
#include"dll.h"
node* findMidPoint(node *start){
	node *f1,*f2;
	f1 = f2 = start;
	if(start == NULL)
		return start;
	while(f2 != NULL && f2->next != NULL){
		f1 = f1->next;
		f2 = f2->next->next;
	}
	return f1;
}
node* convertDllToBst(node* start){
	node *temp,*p,*n;
	if(!start || !start->next){
		start->next = start->prev = NULL;
		return start;
	}
	temp = findMidPoint(start);
	p = start;
	while(p->next!=temp)
		p = p->next;
	p->next = NULL;
	n = temp->next;
	temp->next = NULL;
	temp->prev = convertDllToBst(start);
	temp->next = convertDllToBst(n);
	return temp;
}
void displayDllInorder(node *start){
	if(start == NULL)
		return;
	displayDllInorder(start->prev);
	printf("%d ",start->data);
	displayDllInorder(start->next);
}
int main(){
	node *start = NULL;
	for(int i = 1; i <= 7; i++){
		start = insertAtEnd(start,i);
	}
	start = convertDllToBst(start);
	displayDllInorder(start);
}
