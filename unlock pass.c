#include<stdio.h>
int main()
{
	int pass[]={0,4,2,7};
	int a,b,j;
	
	printf("Enter password..");
	scanf("%d",&a);
	
	if(a==360)
	{
		printf("Hacking started..\n");
		printf("Enter the system code..");
		scanf("%d",&b);
	}
	else
		printf("System is locked..\n");
		printf("Your location is strtessed..\n");
		printf("Alarm is on..\n");
		printf("The system will blast in 5 seconds..");	
	if(a==360 && b==007)	
	{
		{
			for(j=0;j<=9;j++)
			if(j==4)
			{
				for(j=0;j<=9;j++)
				if(j==2)
				{
					for(j=0;j<=9;j++)
					if(j==7)
					{
						printf("Hacked succesfully system is unlocked:");
					}
				}
			}
		}
	}
}