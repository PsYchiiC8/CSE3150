#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* print out an error message and exit */
void my_error(char *s)
{
    perror(s);
    exit(1);
}

/* Concatnate two strings.
 * Dynamically allocate space for the result.
 * Return the address of the result.
 */
char *my_strcat(char *s1, char *s2)
{
    // TODO
    char* concat = malloc(strlen(s1) + strlen(s2) + 1);
    if(concat == NULL){
        my_error(concat);
    }
    strcpy(concat, s1);
    strcat(concat, s2);
    return concat;
}

int main(int argc, char *argv[])
{
    char    *s;
    char *copy;

    s = my_strcat("", argv[0]);

    for(int i = 1; i < argc; i++){
        copy = s;
        s = my_strcat(copy, argv[i]);
        free(copy);
    }

    printf("%s\n", s);
    free(s);

    return 0;
}
