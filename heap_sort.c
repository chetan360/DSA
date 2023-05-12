/* Assignment 2 set B. a) */
#include<stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i) {
    int maxInd = i;
    int l = 2*i+1; //left child
    int r = 2*i+2; //right child

    if(l < n && arr[l] > arr[maxInd]) {
        maxInd = l;
    }

    if(r < n && arr[r] > arr[maxInd]) {
        maxInd = r;
    }

    //swap if parret less than child
    if(maxInd != i) {
        swap(&arr[i], &arr[maxInd]);
        heapify(arr, n, maxInd);
    }
}

void heapsort(int arr[], int n) {
    for(int i=n/2-1; i>=0; i--) {
        //heapify down
        heapify(arr, n, i);
    }

    for(int i=n-1; i>0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[50], n;
    
    printf("How many values : ");
    scanf("%d", &n);

    printf("Enter %d values :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    heapsort(arr, n);

    printf("Sorted values after heap sort :\n");
    for(int i=0; i<n; i++) {
        printf(" %d ", arr[i]);
    }

}