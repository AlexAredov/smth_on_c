#include <stdio.h>
#include <string.h>

int main()
{
    char A[100];
    char B[100];
    scanf("%s", A);
    scanf("%s", B);
    if(strlen(A) > strlen(B)){
        printf("%s", "1 > 2");
    }
    else{
        printf("%s", "1 < 2");
    }
}