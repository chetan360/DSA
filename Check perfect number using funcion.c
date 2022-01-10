/*program for ceck given number is perfect or not*/
#include<stdio.h>
int perfect(int num)
{
	int n,sum=0,i;
	n=num;
	for(i=1;i<n;i++)
	{
		if(num%i==0)
		sum+=i;
	}
	if(num==sum)
		printf("%d is Perfect number..",num);
	else
		printf("%d is not Perfect number..",num);
	return(num);
}
int main()
{
	int a;
	printf("Enter any number : ");
	scanf("%d",&a);
	perfect(a);
	return(0);
}