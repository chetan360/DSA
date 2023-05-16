#include<stdio.h>
#include<string.h>

int linearSearch(char city[][20], int n, char key[]) {
    for(int i=0; i<n; i++) {
        if(strcmp(city[i], key) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char city[20][20];
    int n;
    printf("How many city names : ");
    scanf("%d", &n);
    
    printf("Enter %d city names :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%s", city[i]);
    }
    
    char key[20];
    printf("Enter city to search : ");
    scanf("%s", key);
    
    int i = linearSearch(city, n, key);
    
    if(i == -1) {
        printf("Not found.");
    } else {
        printf("Found at %d index.", i);
    }
    
    return 0;
}