#include <stdio.h>
#include <stdlib.h>
//из строки в число
int main()
{
    char sss[10];
    scanf("%s", sss);
    int pos = 1;
    int n = 1;
    int i = 0;
    if (sss[i] == '-'){
        pos = 0;
        i++;
    }
    int res = 0;
    float res1 = 0;
    while (sss[i] != '\0'){
        if (sss[i] == '.'){
            n = 0;
            i++;
        }
        if (n == 0){
            int k = sss[i] - '0';
            res1 = res1 + k* 0.1;
        }
        else{
            int k = sss[i] - '0';
            res = res * 10 + k;
        }
        i++;
    }
    float result = res + res1;
    if (pos == 0){
        result = result * -1;
    }
    printf("%f", result); //вывод результата преобразования
    return 0;
}