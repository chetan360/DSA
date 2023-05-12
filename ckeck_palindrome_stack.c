#include<stdio.h>
#include<string.h>

int stack[100];
int top = -1;
char str[30];

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

void ckeck_palindrome() {
    for(int i=0; i<strlen(str); i++) {
        if(str[i] != pop(top)) {
            printf("Not palindrome.");
            return;
        }
    }
    printf("String is palindrome.");
}

int main() {
    int i;
    printf("Enter a string : \n");
    gets(str);
    for(i=0; i<strlen(str); i++) {
        push(str[i]);
    } 

    ckeck_palindrome(); 

    return 0;
}