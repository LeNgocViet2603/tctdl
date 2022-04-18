#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[100],n;
	// declare pointer file
	FILE *file;
	// asign file equal using fopen function
	file = fopen("D:\\hocCTDL&GT\\input.txt","r");
	//if openning the file have error then notify
	if(file == NULL){
		printf("can't found this file\n");
		return -1;	
	}else{
		//read first line and save it in the variable n 
		fscanf(file,"%d",&n);
		for(int i =0 ;i<n;i++){
			//fscanf(file,"%d",&n);
			fscanf(file,"%d",&a[i]);
			printf("%d ",a[i]);
		}
	}
	return 0;
}
