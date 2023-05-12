#include<stdio.h>
#include"swapnil.h"


int main()
{
    int num,val;
    while(1){
    printf("       MENU\n");
    printf("1.enQueue DLL\n");
    printf("2.deQueue DLL\n");
    printf("3.display DLL");
    printf("Exit \n");

    printf("choose op : ");
    scanf("%d",&num);
    switch(num){
        case 1 :
                printf("Enter new elem. : ");
                scanf("%d",&val);
                   enQueue(val);
                   break;
        case 2 : 
               deQueue();
               break;
        case 3:
               display();
               break;
        default : return 1;
    }
     printf("\n\n------------------\n");
    }
    return 0;
}
