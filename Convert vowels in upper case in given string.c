//program for input a string and convert all vowels in upper case
#include<stdio.h>
#include<string.h>
int main()
{
	char a[30];
	int i;
	printf("Enter a string to convert all vowels in upper case:\n");
	gets(a);
	printf("Given string is:\n");
	puts(a);
	i=0;
	while(a[i]!='\0')
	{
		if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u')
			a[i]=a[i]-32;
		i++;
	}
	printf("After converting vowels into upper case the string becomes:\n");
	puts(a);
}