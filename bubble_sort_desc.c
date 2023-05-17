#include<stdio.h>

int arr[50], n;

void bsort() {
    for(int pass=1; pass<n-1; pass++) {
        for(int i=0; i<n-pass; i++) {
            if((arr[i] < arr[i+1])) {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
}

void input() {
    printf("How many values : ");
    scanf("%d", &n);
    
    printf("Enter %d value :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        
    }
}

void output() {  
    printf("\nData after sorting..\n");    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    
}

int main() {
    input();
    bsort();
    output();
    return 0;
}