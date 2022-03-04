#include<stdio.h>
int main()
{
	int a[3][3],i,j,isupper;
	printf("Enter values of 3x3 matrix:\n");
	
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
			scanf("%d",&a[i][j]);
	}
	
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
			if(j<i && a[i][j]==0)
				isupper=1;
	}
	
	if(isupper==1)
		printf("\nThe matrix is upper triangular..\n");
	else
		printf("\nThe matrix is not upper triangular..\n");
		
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	
	return(0);
}
