#include<stdio.h>
#include"slist.h"

int main() {
    NODEPTR slist = NULL;
    int ch;

    do {
        printf("\n\n\n          MENU\n");
        printf("1. create.\n");
        printf("2. display.\n");
        printf("3. exit.\n");

        printf("Enter your choise : ");
        scanf("%d", &ch);

        switch (ch) {
        case 1: slist = create(slist);
            break;
        case 2: display(slist);
            break;
        }
    } while(ch != 3);
    return 0;
}