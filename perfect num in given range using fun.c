#include<stdio.h>
int perfect(int stno, int enno)
{
	int temp,sum,i,num;
	for(num=stno;num<=enno;num++)
	{
		temp=num;
		sum=0;
		for(i=1;i<temp;i++)
		{
			if(num%i==0)
			sum+=i;
		}
		if(num==sum)
			printf("%d ",num);		
	}
	return(num);
}
int main()
{
	int stno,enno,go;
	printf("Enter starting number:");
	scanf("%d",&stno);
	
	printf("Enter ending number:");
	scanf("%d",&enno);
	
	go=perfect(stno,enno);
	return(0);
}