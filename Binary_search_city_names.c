#include<stdio.h>
#include<string.h>

int binary_search(char city[][20], int lb, int ub,  char key[]) {
    int mid;

    while(lb <= ub) {
        mid = (lb+ub)/2;
        if(strcmp(city[mid], key) == 0) {
            return mid;
        } else if(strcmp(key, city[mid]) < 0) {
            ub = mid - 1;
        } else {
            lb = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    char city[20][20];
    printf("How many names : ");
    scanf("%d", &n);

    printf("Enter %d city names :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%s", city[i]);
    }

    char key[50];
    printf("Enter city to search : ");
    scanf("%s", key);

    int i = binary_search(city, 0, n-1, key);

    if(i == -1) {
        printf("City not found.");
    } else {
        printf("Found at %d index.", i);
    }

    return 0;
}