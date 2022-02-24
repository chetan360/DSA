#include<stdio.h>
int main()
{
    int a,b,c,md;
    float ac;
    printf("\n1.Add two numbers:\n");
    printf("\n2.Substract two numbers:\n");
    printf("\n3.Multiplay two numbers:\n");
    printf("\n4.Devide two numbers:\n");
    printf("\n5.Calculate Area of circle :\n");
    printf("\n6.Exit:\n");
    while(1){
    printf("\nChoose any operation:..\n");
    scanf("%d",&md);
	switch(md)
    {
        case 1: printf("\nYou chosse Adiition..\n");
                printf("Enter two numbers:\n");
                scanf("%d%d",&a,&b);
                c=a+b;
                printf("Addition is %d\n",c);
                break;
        case 2: printf("\nYou chosse Substraction..\n");
                printf("Enter two numbers:\n");
                scanf("%d%d",&a,&b);
                c=a-b;
                printf("Substraction is %d\n",c);
                break;
        case 3: printf("\nYou chosse Multiplication..\n");
                printf("Enter two numbers:\n");
                scanf("%d%d",&a,&b);
                c=a*b;
                printf("Multiplication is %d\n",c);
                break;
        case 4: printf("\nYou chosse Division:\n");
                printf("Enter two numbers\n");
                scanf("%d%d",&a,&b);
                ac=(float)a/(float)b;
                printf("Division is %f\n",ac);
                break;
        case 5: printf("\nYou chosse Area of circle..\n");
                printf("Enter Radius of Circle:\n");
                scanf("%d",&a);
                ac=3.14*(float)a*(float)a;
                printf("Area of circle is %f\n",ac);
                break;
        default :return(1); 
    }
	}
	return(0);
}