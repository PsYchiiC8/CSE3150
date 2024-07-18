
#include <stdio.h>
int main(void){
    printf("Hello, World!\n");

    int i = 0;
    int total = 0;
    while(i < 200){
        if(i % 2 == 0){
            total += i;
        }
        i++;
    }
    printf("%d\n", total);
    return 0;
}