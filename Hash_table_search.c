#include<stdio.h>

int arr[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1, -1};

void insert() {
    int x, y;
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Enter data : ");
    scanf("%d", &x);

    y = x % n;
    if(arr[y] == -1) {
        arr[y] = x;
    } else {
        for(int i=1; i<n; i++) {
            if(arr[y+i] == -1) {
                arr[y+i] = x;
                break;
            }
        }
    }
}

void display() {
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("  Ind  | value\n");
    printf(" --------------\n");
    for(int i=0; i<n; i++) {
        printf("   %d   -  %d\n", i, arr[i]);
    }
}

int search(int x) {    
    int y;
    int n = sizeof(arr)/sizeof(arr[0]);

    y = x % n;
    if(arr[y] == x) {
        return 1;
    } else {
        for(int i=1; i<n; i++) {
            if(arr[y+i] == x) {
                return 1;
            }
        }
        return -1;
    }
}

int main() {
    int ch, x;
    do {
        printf("\n\n          Menu\n");
        printf("1. Insert.\n");
        printf("2. Display.\n");
        printf("3. Search.\n");
        printf("4. Exit.\n");
        printf("----------------------------------\n");

        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;
        
            case 2:
                display();
                break;
            case 3:
                printf("Enter the value to be search : ");
                scanf("%d", &x);
                if(search(x) == -1) {
                    printf("Not Found.\n");
                } else {
                    printf("Found.\n");
                }
                break;
        }
    } while(ch < 4);

    return 0;
}