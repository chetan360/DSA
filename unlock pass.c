#include<stdio.h>
#include<stdlib.h>

int main() {
  int a,b,j;
  int pass = 2898;
  
  printf("Enter password:");
  scanf("%d",&a);
  
  if(a==pass) {
    printf("Unlock successfully..");
    exit(0);
  }
  
  if(a==360) {
    
    printf("Hacking started..");
    printf("\nEnter the system code:");
    scanf("%d",&b);
    
      if(a==360 && b==007) {
        for(j=0;j<=9;j++)
          if(j==2) { 
            printf("\n1st digit is matched %d\n",j);
            for(j=0;j<=9;j++)
            if(j==8) {
              printf("2nd digit is matched %d\n",j);
            for(j=0;j<=9;j++)
               if(j==9) {
                 printf("3rd digit is matched %d\n",j);
               for(j=0;j<=9;j++)
                 if(j==8) {
                   printf("4th digit is matched %d\n",j);
                     printf("Hacked succesfully system is unlocked:");
                 }
             }
            }
         }
      }
  } else {
    printf("Wrong password..\n");
    printf("Your location is strtessed..\n");
    printf("Alarm is on..\n");
    printf("The system will blast in 5 seconds..");  
  }
  
  return 0;
}
