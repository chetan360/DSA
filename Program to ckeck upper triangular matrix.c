#include<stdio.h>
int main()
{
	int a[3][3];
	int i,j,is_upper;
	
	printf("Enter elements of matrix 3x3:\n");
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	is_upper = 1;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			if(j<i && a[i][j]!=0)
			{
				is_upper = 0;
			}
		}
	}
	
	if(is_upper == 1)
	{
		printf("\nThe matrix is upper triangular matrix..\n");
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
		printf("\nThe matrix is not upper triangular matrix..");
	}
	
	return(0);

}