#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("n = ");
    scanf("%d", &n);

    int m = n;
    //TODO
    //add code below
    int visited[30];
    n = 0;
    visited[0] = m;
    int visited_i = 1;
    int sum = m;

    while(n == 0){
        int hunds = sum / 100;
        int tens = (sum / 10) % 10;
        int ones = sum % 10;
        sum = hunds * hunds + tens * tens + ones * ones;
        printf("%d\n", sum);

        if(sum == 1) {
            n = 1;
        } else if(sum == 4){
            n = -1;
        } else {
            for (int i = 0; i < 30; i++) {
                if (visited[i] == sum) {
                    n = -1;
                }
            }
        }
        visited[visited_i] = sum;
        visited_i++;
    }

    if (n == 1){
        printf("%d is a happy number.\n", m);
    } else if (n == -1){
        printf("%d is NOT a happy number.\n", m);
    }
    return 0;
}