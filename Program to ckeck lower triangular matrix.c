#include<stdio.h>
int main()
{
	int a[3][3];
	int i,j,is_lower;
	
	printf("Enter elements of matrix 3x3:\n");
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	is_lower = 1;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			if(i<j && a[i][j]!=0)
			{
				is_lower = 0;
			}
		}
	}
		if(is_lower == 1)
	{
		printf("\nThe matrix is lower triangular matrix..\n");
		for(i=0;i<=2;i++)
	    {
			for(j=0;j<=2;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("\nThe matrix is not lower triangular matrix..");
	}
	return(0);
}