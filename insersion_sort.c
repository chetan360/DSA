#include<stdio.h>

int arr[20], n, i , j;

void insertion_sort() {
    for(i=1; i<n; i++) {
        int newelt = arr[i];
        j = i-1;
        while(arr[j]>newelt && j>=0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = newelt;
    }
}

int main() {
    printf("enter how many elements : ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n");
    insertion_sort();
    for(i=0; i<n; i++) {
        printf(" %4d", arr[i]);
    }
    return 0;

}