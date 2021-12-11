#include <stdio.h>
#include <stdlib.h>
//из строки в число
int main()
{
    char sss[10];
    scanf("%s", sss);
    int pos = 1;
    int i = 0;
    if (sss[i] == '-'){
        pos = 0;
        i++;
    }
    int res = 0;
    while (sss[i] != '\0'){
        int k = sss[i] - '0';
        res = res * 10 + k;
        i++;
    }
    if (pos == 0){
        res = res * -1;
    }
    printf("%d",res); //вывод результата преобразования
    return 0;
}