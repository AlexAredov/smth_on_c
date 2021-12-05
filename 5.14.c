#include <stdio.h>
#include <string.h>

int main()
{
    char *A = "asdfghjkl";
    char *B = "hjkl";
    if(strlen(A) > strlen(B)){
        printf("%s", "Yes");
    }
    else{
        printf("%s", "No");
    }
}