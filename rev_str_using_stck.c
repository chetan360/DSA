#include<stdio.h>
#include"cststack.h"

char* rev(STACK *s, char str[30]) {
    int i;
    //store str in stack
    for(i=0; str[i]!='\0'; i++) {
        push(s, str[i]);
    }
    //pop and store in same str from top
    for(i=0; !is_empty(s); i++) {
        str[i] = pop(s);
    }
}


int main() {
    char str[30];
    STACK s;
    init(&s);

    printf("Enter any string :\n");
    gets(str);

    rev(&s, str);

    printf("Reversed string is :");
    printf("\n%s", str);

    return 0;
}