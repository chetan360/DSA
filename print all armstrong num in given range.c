//program for display all armstrong in given range
#include<stdio.h>
int main()
{
	int stno,enno,r,n,s,t;
	printf("Enter the range to display all prime numbers in it:");
	scanf("%d%d",&stno,&enno);
	
	for(n=stno;n<=enno;n++)
	{
		t=n;
		s=0;
		
		while(t!=0)
		{
			r=t%10;
			s=s+(r*r*r);
			t=t/10;
		}
		if(s==n)
			printf("%d ",n);
	}
}