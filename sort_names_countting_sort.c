#include<stdio.h>
#include<string.h>

char name[50][10];
int i, n;
  
void countSort() {  
   char output[50][10];
   int c[26];
  
   for (i = 0; i < 26; i++) {  
      c[i] = 0;
   }  
    
   for(i = 0; i < n; i++) {
      c[name[i][0]-'a']++;
   }
           
   for(i = 1; i < 26; i++)  {
      c[i] += c[i-1];
   }
   
   for (i = n - 1; i >= 0; i--) { 
     strcpy(output[--c[name[i][0]-'a']], name[i]);
   }  
  
   for(i = 0; i < n; i++) {  
      strcpy(name[i], output[i]);
   }  
}  

int main() {  
    
    printf("How may names : ");
    scanf("%d", &n);
    printf("Enter %d names \n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", name[i]);
    } 
    
    countSort();
    
    printf(" \nNames in sorted order by frist alphabate : \n");
    for (i = 0; i < n; i++) {
        printf("%s\n", name[i]);
    }
    
    return 0;  
}