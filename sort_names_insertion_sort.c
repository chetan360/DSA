#include<stdio.h>
#include<string.h>

void insertion_sort(char name[][25], int n) {
    for(int upos=1; upos<n; upos++) {
        char newelement[25];
        strcpy(newelement, name[upos]);
        int spos = upos - 1;
        while(strcmp(name[spos], newelement)>0 && spos>=0) {
            strcpy(name[spos+1], name[spos]);
            spos--;
        }
        strcpy(name[spos+1], newelement);
    }
}

int main() {
    char name[20][25];
    int n, i;
    printf("How many names : ");
    scanf("%d", &n);

    printf("Enter %d names :\n", n);
    for(i=0; i<n; i++) {
        scanf("%s", name[i]);
    }

    insertion_sort(name, n);

    printf("Sorted names are :\n");
    for(i=0; i<n; i++) {
        printf("%s\n", name[i]);
    }
}