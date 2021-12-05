#include <stdio.h>
#include <string.h>

int main()
{
    char *s = "asdfghjkl";
    char *ss = "hjkl";
    char *istr = strstr(s, ss);
    printf("%d", (int)(istr - s));
}