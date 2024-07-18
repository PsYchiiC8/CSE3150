// Find the smallest positive integer that can be expressed as a sum of two positive cube numbers in two different ways.

// More specifically, we want to find the smallest n such that n == i1*i1*i1 + j1*j1*j1,
// n == i2*i2*i2 + j2*j2*j2, and (i1, j1) and (i2, j2) are not the same in the sense that
// not only (i1, j1) not equal to (i2, j2), but also (i1, j1) not equal to (j2, i2).

// We practice using loops in this assignment.
// Also, we practice how to do an early exit in a loop. We exit the loop once we find the smallest n.

#include <stdio.h>
int main()
{
    int i, j, n;
    // We assume the smallest such n is no more than 1000000
    for (n = 1; n <= 1000000; n++)
    {
        // Use count to record the number of different ways of summing two positive cube numbers to n
        int count = 0;
        // TO DO
        // Fill in code below
        int prvI, prvJ;
        int true = 1;
        for (int i = 1; i * i * i < n; i++){
            for (int j = 0; i * i * i + j * j * j <= n; j++){
                if (i * i * i + j * j * j == n){
                    if (count == 0){
                        prvI = i;
                        prvJ = j;
                        count++;
                    }

                    if (count == 1){
                        //printf("Count 2: %d %d\n ", i,j);
                        if (i != prvI && j != prvI){
                            true = 0;
                            //printf("Count 3: %d %d %d %d \n", i,j,prvI,prvJ);
                            count ++;
                            break;
                        }
                    }
                }
            }
            if (!true){
                break;
            }
        }
        if (!true){
            break;
        }
    }

    // Do not change code below
    printf("%d is the solution:\n", n);
    for (i = 1; i <= 100; i++)
        for (j = i; j <= 100; j++)
        {
            if (i * i * i + j * j * j == n)
            {
                printf("%d * %d * %d + %d * %d * %d = %d\n", i, i, i, j, j, j, n);
            }
        }

    return 0;
    // Do not try to hard code the solution, that is not the way to learn.
}