#include <stdio.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node NODE;
struct list{
	NODE *head;
};
typedef struct list LIST;
NODE *createNode(int val){
	NODE *p = new NODE();
	if(p==NULL){
		printf("cannot create node!");
		return NULL;
	}
	p->data = val;
	p->next = NULL;
	return p;
}
void createList(LIST &l){
	l.head = NULL;
}
void addNodeAtHead(LIST &l,NODE *p){
	if(l.head == NULL){
		l.head = p;
	}else{
		p->next = l.head;
		l.head = p;
	}
}
void addNodeAtTail(LIST &l,NODE *p){
	if(l.head == NULL){
		l.head = p;
	}else{
		NODE *tmp = l.head;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = p;
		p->next = NULL;
	}	
}
void printList(LIST l){
	if(l.head == NULL){
		printf("LIST dang trong!\n");
		return;
	}else{
		while(l.head != NULL){
			printf("%d ",l.head->data);
			l.head = l.head->next;
		}
	}
	
}
int main(){
	int n;
	LIST mylist;
	createList(mylist);
	printf("nhap so node can them!\n");
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		int val;
		printf("Nhap gia tri node:\n");
		scanf("%d",&val);
		NODE *p = createNode(val);
		addNodeAtTail(mylist,p);
	}
	printList(mylist);
	return 0;
}
