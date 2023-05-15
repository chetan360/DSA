#include<stdio.h>

int get_max(int arr[], int n) {
    int max=arr[0];
    for(int i=1; i<n; i++) {
        if(max<arr[i]) {
            max=arr[i];
        }
    }
    return max;
}

int digit_count(int max) {
    int c=0;
    while(max!=0) {
        max=max/10;
        c++;
    }
    return c;
}

void count_sort(int arr[], int n, int pos) {
    int c[10]={0};
    int o[30];
    for(int i=0; i<n; i++) {
        c[(arr[i]/pos)%10]++;
    }
    for(int i=0; i<9; i++) {
        c[i+1] += c[i];
    }
    for(int i=n-1; i>=0; i--) {
        o[--c[(arr[i]/pos)%10]] = arr[i];
    }
    for(int i=0; i<n; i++) {
        arr[i] = o[i];
    }
}

void recr_csort(int arr[], int n) {
    int max, c, pos=1;
    max = get_max(arr, n);
    c=digit_count(max);
    while(c>0) {
        count_sort(arr, n, pos);
        pos=pos*10;
        c--;
    }
}

int main() {
    int arr[30], n;
    printf("How many values : ");
    scanf("%d", &n);
    
    printf("Enter %d values :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    recr_csort(arr, n);
    
    printf("Sorted array is :\n");
    for(int i=0; i<n; i++) {
        printf("%4d", arr[i]);
    }
    
    return 0;
}