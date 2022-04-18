#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[100],n;
	printf("nhap so luong phan tu");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("nhap a[%d]",i);
		scanf("%d",&a[i]);
	}
	FILE *f;
	f = fopen("D:\\hocCTDL&GT\\input.txt","w+");
	if(f == NULL){
		printf("Can not open this file\n");
		return -1;
	}else{
		fprintf(f,"%d\n",n);
		for(int j = 0;j<n;j++){
			fprintf(f,"%d  ",a[j]);
		}
	}
	return 0;
}
