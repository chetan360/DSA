//programe for inpute palindrom number using function
#include<stdio.h>
int check(int num)
{
	int sum=0,r,temp;
	temp=num;
	while(num!=0)
	{
		r=num%10;
		sum=(sum*10)+r;
		num=num/10;
	}
	if(sum==temp)
		printf("%d is Palindrom..",temp);
	else
		printf("%d is not Palindrome..",temp);
}
int main()
{
	int n,m;
	printf("Enter any number:");
	scanf("%d",&n);
	check(n);
	return(0);
}