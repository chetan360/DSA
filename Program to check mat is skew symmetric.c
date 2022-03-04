#include<stdio.h>
int main()
{
	int a[3][3];
	int i,j,is_skew;
	printf("Enter values of mat..\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(a[i][j]==-a[j][i])
				is_skew=1;
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	if(is_skew==1)
		printf("The matrix is skew symmetric");
	else
		printf("The matrix is not skew symmetric");
	return(0);
}
	