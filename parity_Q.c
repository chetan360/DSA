#include<stdio.h>
#include<stdlib.h>

#define max 20

int arr[max];
int front = -1;
int rear = -1;
int isempty(){
    if(rear == max-1){
        return 1;
    }else{
        return 0;
    }
}
void cheak(int val){
int i,j;
for(i=0; i<=rear; i++){
    if((val > arr[i])){
        for(j=rear; j>=0; j-- ){
            arr[j] = arr[j-1];
        }
        arr[i] = val;
        return;
    }
   }
   arr[i] = val;
}
void  enQueue(int val){
    if(isempty()){
     printf("OVERFLOW stack do not insert elements \n");
     return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        arr[rear] = val;
        return;
    }
    cheak(val);
    rear++;
    
}
void display(){
    for(int i= front; i<=rear; i++){
        printf("%d   ",arr[i]);
    }
}
int main()
{
    int num,val;
    printf("1.insert an elements into queue \n");
    printf("2.delete an elements from queue \n");
    printf("3.display \n");
    printf("Exit \n");
    do {
    printf("choose op : ");
    scanf("%d",&num);
    switch(num){
       case 1: 
             printf("Enter new elements : ");
             scanf("%d",&val);
          inQueue(val);
             break;
         case 2:
            printf("Enter value to delete : ");
            scanf("%d",&val);
           // deQueue(val);
         break;
        case 3:
              display();
              break;
        default : return 1;

    }
    printf("\n\n---------------------------\n");
   }while(num != 4);
    return 0;
}