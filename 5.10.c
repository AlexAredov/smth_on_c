#include <stdio.h>
#include <stdlib.h>
//из строки в число
int main()
{
    char *sss = "652"; //строка для преобразования
    int n = atoi(sss); //преобразование строки в число типа int
    printf("%d",n); //вывод результата преобразования
}