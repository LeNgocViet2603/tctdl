#include<stdio.h>
// dinh nghia cau truc node
struct node{
	int data;
	struct node *next;
};
// thay the ten cau truc la node thanh NODE
typedef struct node NODE;
//dinh nghia cau truc 1 dslk
struct list{
	// con tro head tro vao dau danh sach
	NODE *head;
};
// thay the ten cau truc la list thanh LIST
typedef struct list LIST;
//khoi tao list
void createList(LIST &l){
	l.head = NULL;
}
// khoi tao node
NODE *createNode(int val){
	//cap phat vung nho cho node
	NODE *p = new NODE;
	if(p==NULL){
		printf("cap phat vung nho khong thanh cong do bo nho khong du!");
		return NULL;
	}
	p->data = val;
	p->next = NULL;
	return p;
}
// ham them node vao dau linked list
void addBegin(LIST &l,NODE *p){
	// kiem tra danh sach co dang rong khong
	if(l.head == NULL){
		//neu danh sach rong thi gan con tro head bang node p luon
		l.head = p;
		
	}
	else{
		// tao mot lien ket tu node can them den con tro head dang tro vao danh sach
		p->next = l.head;
		// cap nhat lai con tro dau cua danh sach bang p
		l.head = p;
	}

	
}

// ham them node vao cuoi linked list
void addLast(LIST &l,NODE *p){
	// neu danh sach rong 
	// thi gan head bang p luon
	if(l.head == NULL){
		l.head = p;		
	}
	else{
		NODE *tmp=l.head;
		/*
		can phai tao mot con tro tmp de thao tac
		nham muc dich khong thay doi l.head(luu tru dia chi l.head)
		neu khong co bien tmp thi trong dslk luon luon chi co hai node
		while(l.head->next != NULL){
			l.head = l.head->next;
		}
		p->next = NULL;
		l.head->next = p;*/
		// duyet den phan tu cuoi cung cua danh sach
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		// gan next cua node can them vao ( node p ) den null
		p->next = NULL;
		// gan node cuoi cung cua danh sach den node p
		// luc nay p se la node cuoi cung cua danh sach
		tmp->next = p;
	}
}
// ham tra ve so node trong danh sach lien ket
int getLengthList(LIST l){
	int n=1;
	while(l.head->next != NULL){
		l.head = l.head->next;
		n++;
	}
	return n;
}
// ham them node tai vi tri bat ki dua vao vi tri them
void addAtIndex(LIST &l,int index,NODE *p){		
	if(index == 0){
		addBegin(l,p);
	}else{
		if(index == getLengthList(l)){
			addLast(l,p);
		}else{
			NODE *tmp = l.head;			
			for(int i=0;i<index-1;i++){
				tmp=tmp->next;
			}
			p->next = tmp->next;
			tmp->next = p;
			
		}
	}
}
// ham xoa node dau
void deleteBegin(LIST &l){
	if(l.head == NULL){
		return;
	}
	else{
		// neu danh sach lk co 1 phan tu
		if(l.head->next == NULL){
			delete l.head;
			l.head = NULL;
		}else{ //dslk co n phan tu
			NODE *tmp = l.head;
			l.head=l.head->next;
			delete tmp;
		}
		
	}
}
void deleteEnd(LIST &l){
	if(l.head == NULL){
		return;
	}
	else{
		// neu danh sach lk co 1 phan tu
		if(l.head->next == NULL){
			delete l.head;
			l.head = NULL;
		}
		else{
			NODE *prevNode,*tmp_head;
			tmp_head = l.head;
			while(tmp_head->next != NULL){
				// con tro prevNode luu tru gia tri cua node truoc node hien tai
				prevNode = tmp_head;
				tmp_head = tmp_head->next;			
			}
			//gan node truoc node hien tai den null
			prevNode->next = NULL;
			// xoa,giai phong vung nho cho node hien tai
			delete tmp_head;
		}		
	}
}
// ham kiem tra gia tri node nhap vao co nam trong danh sach khong
bool isNodeInList(LIST l,int val){
	// duyet danh sach lien ket 
	// neu l.head chua tro toi NULL
	// neu dieu kien trong while la l.head->next thi khi duyet se mat node cuoi cung
	// cho nen dieu kien trong while la l.head != NULL
	while(l.head != NULL){
		if(l.head->data == val){
			return true;
		//	break;
		}
		l.head = l.head->next;
	}
	return false;
}
void deleteWithVal(LIST &l,int val){
	// neu gia tri nhap vao khong nam trong danh sach
	// thi in cau thong bao khong tim thay gia tri do trong danh sach va thoat chuong trinh
	if(!isNodeInList(l,val)){
		printf("Gia tri cua node nhap vao khong co trong danh sach!\n ");
		return;
	}
	else{
		// neu node can xoa la node dau tien trong danh sach
		// thi goi ham xoa dau
		if(l.head->data == val){
			deleteBegin(l);
		}
		else{
			// khai bao con tro tmp_head de duyet danh sach
			// khai bao con tro prevNode de luu giu gia tri node truoc do
			NODE *tmp_head,*prevNode;
			tmp_head = l.head;
			while(tmp_head->data != val){
				prevNode = tmp_head;		
				tmp_head = tmp_head->next;
			}
			// neu node can xoa la node cuoi cung trong danh sach
			// thi goi ham xoa cuoi
			if(tmp_head->next == NULL){
				deleteEnd(l);
			}
			//neu node can xoa khong phai la node dau va node cuoi
			else{
				// cho node truoc node hien tai can xoa tro den node tiep theo sau node can xoa
				prevNode->next = tmp_head->next;
				// thuc hien xoa,giai phong vung nho cho node hien tai
				delete tmp_head;
			}
		}
	}

}
// in danh sach kien ket
void printList(LIST l){
	//printf("DANH SACH BAN VUA NHAP LA:\n");
	if(l.head == NULL){
		printf("danh sach dang rong\n");
		return;
	}
	while(l.head != NULL){
		printf("%d  ",l.head->data);
		l.head = l.head->next;
	}
		printf("\n");
}

int main(){
	LIST l;
	int n,val,index,newnode;
	createList(l);
	printf("Nhap so luong node can them !\n");
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		printf("Nhap gia tri node:\n");
		scanf("%d",&val);
		NODE *p = createNode(val);
		addLast(l,p);
	}
	printList(l);
	deleteBegin(l);
	printf("danh sach sau khi xoa dau\n");
	printList(l);
	deleteEnd(l);
	printf("danh sach sau khi xoa cuoi\n");
	printList(l);
	printf("Nhap gia tri cua node can xoa!\n");
	int valNode;
	scanf("%d",&valNode);
	deleteWithVal(l,valNode);
	printf("danh sach sau khi xoa!\n");
	printList(l);
	printf("nhap vi tri can chen vao!\n");
	scanf("%d",&index);	
	printf("nhap gia tri node can them\n");
	scanf("%d",&newnode);
	NODE *k = createNode(newnode);	
	addAtIndex(l,index,k);
	printf("danh sach sau khi them\n");
	printList(l);
}

