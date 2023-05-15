#include <stdio.h>
#include <string.h>

int partition(char city[][20], int lb, int ub) {
    int dn = lb+1;
    int up = ub;
    char pivot[20];
    strcpy(pivot, city[lb]);

    do {
        while(strcmp(city[dn], pivot) < 0 && dn <= ub) {
            dn++;
        }
        while(strcmp(city[up], pivot) > 0 && up > lb) {
            up--;
        }
        if(dn < up) {
            char t[20];
            strcpy(t, city[dn]);
            strcpy(city[dn], city[up]);
            strcpy(city[up], t);
        }
    } while(dn < up);

    strcpy(city[lb], city[up]);
    strcpy(city[up], pivot);
    return up;
}

void quickSort(char city[][20], int lb, int ub) {
    if(lb < ub) {
        int pi = partition(city, lb, ub);
        quickSort(city, lb, pi-1);
        quickSort(city, pi+1, ub);
    }
}

int main() {
    char city[20][20];
    int n;

    printf("How many cities : ");
    scanf("%d", &n);

    printf("Enter %d city names :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%s", city[i]);
    }

    quickSort(city, 0, n-1);

    printf("Sorted city names are :\n");
    for(int i=0; i<n; i++) {
        printf("%s\n", city[i]);
    }

    return 0;
}