#include <stdio.h>
#include <stdlib.h>
//из строки в число
int main()
{
    char *sss = "652.55"; //строка для преобразования
    float n = atof(sss); //преобразование строки в число типа float
    printf("%f",n); //вывод результата преобразования
}