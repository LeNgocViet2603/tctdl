#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *next;
};
node* taoNode(int val){
	node *tmp;
	tmp=new node();
	tmp->next = NULL;
	tmp->value=val;
	return tmp;
}
void xuat_DS(node* Head){
	printf("\danh sach day so:\n");
	for(node *p=Head;p != NULL;p=p->next){
		printf("%d    ",p->value);
	}
}
node *them_ptu_dau(node* Head,int value){
	node *tmp = taoNode(value);
	if(Head == NULL){
		Head = tmp;
	}
	else{
		tmp->next=Head;
		Head=tmp;
	}
	return Head;
}

node *chen_list_sorted(node* &head,int value){
	node *tmp = taoNode(value);
	
	if(head == NULL || head->value > tmp->value){
		tmp->next=head;
		head=tmp;
	}
	else{
		node *tmp2 = new node;
		tmp2=head;
		while(tmp2->next != NULL){			
			if(tmp2->value<tmp->value && tmp->value < tmp2->next->value){				
				tmp->next = tmp2->next;
				tmp2->next = tmp;				
				break;
			}
				tmp2 = tmp2->next;	
			}
			tmp2->next = tmp;
	}
	
	return head;
}
int timkiem(node* Head,int so){
	int dem=0;
	for(node *p=Head;p!=NULL;p=p->next){
		if(p->value==so){
			dem++;
			return 1;
		}
	}
	if(dem==0){
		return 0;
	}
}
node *tim_vtri_xoa(node *D, int so)
{
	node *tg;
	tg = D;
	while(tg!=NULL)
	{
		if(tg->value == so)
			return tg;
		tg = tg->next;
	}
}
node *xoa_ptu(node *D, int so)
{
	node *tg, *p;
	p = tim_vtri_xoa(D,so);
	if(p==D)
	{
		D = D->next;
		p->next = NULL;
	}
	else
	{
		tg = D;
		while(tg->next != p)
			tg = tg->next;
		tg->next=p->next;
		p->next = NULL;
	}
	return D;
}


void sapxep_DS(node *Head){
	int tmp;
	for(node *p1=Head;p1!=NULL;p1=p1->next){
		for(node *p2=p1->next;p2!=NULL;p2=p2->next){
			if(p1->value>p2->value){
				tmp=p1->value;
				p1->value=p2->value;
				p2->value=tmp;
			}
		}
	}
}

main(){
	node *D;
	D=NULL;
	int n,value,so,sochen;
	printf("nhap so luong phan tu trong danh sach\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("moi nhap gia tri can bo sung\n");
		scanf("%d",&value);
		D = them_ptu_dau(D,value);
	}
	xuat_DS(D);
	printf("\n Nhap vao so can tim:\n");
	scanf("%d",&so);
	if(timkiem(D,so)){
		printf("co trong day so\n");	
	}
	else{
		printf("\n khong co trong day so");
	}
	sapxep_DS(D);
	xuat_DS(D);
	printf("Nhap so can chen vao: \n");
	scanf("%d",&sochen);
	chen_list_sorted(D,sochen);
	xuat_DS(D);
	printf("\n nhap phan tu can xoa!\n ");
	scanf("%d",&so);
	xoa_ptu(D,so);
	xuat_DS(D);
}
