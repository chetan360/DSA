// to display all prime numbers in given range
#include<stdio.h>
int main()
{
	int stno,enno,i,p;
	printf("Enter the range to display all prime numbers in it: \n");
	scanf("%d%d",&stno,&enno);//stno=1 enno=100
	while(stno<enno)//1<100
	{
		p=0;
		for(i=2;i<=stno/2;++i)//i<=1/2 i.e. 
		{
			if(stno%i==0)//1%2=1 stno=1
			{
				p=1;//condition false i.e. p=0
			}
		}
		if(p==0)//p==0 condi true
		{
			printf("%d ",stno);//print stno=1
			
		}
	++stno;//stno=2 stno goes to start of while loop again
	}
	return(0);
}