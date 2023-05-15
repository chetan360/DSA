#include<stdio.h>
#include<stdlib.h>
void csort(int  x[],int num){
	int out[100],count[10]={0};
	for(int i=0; i<num; i++){
		count[x[i]]++;
	}
	for(int i=0; i<9; i++){
		count[i+1] +=count[i];
	}
	for(int i=0;i<num; i++ ) {
		out[--count[x[i]]] = x[i];
	}
	for(int i=0; i<num; i++){
		x[i] = out[i];
	}
}
int main()
{
	int a[100],num,i;
	printf("how many value : ");
	scanf("%d",&num);
	printf("Enter the data \n");
	for(int i=0; i<num; i++){
		scanf("%d",&a[i]);
	}
	csort(a,num);
	printf("sorted data \n");
		for(int i=0; i<num; i++){
		printf("%d \t",a[i]);
	}
	return 0;
}