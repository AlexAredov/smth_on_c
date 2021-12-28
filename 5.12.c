#include <stdio.h>
#include <string.h>

int main()
{
    //Создаем переменные записываем в них значения
    char s[100];
    char s1[100];
    scanf("%s", s);
    scanf("%s", s1);

    //Ищем первое вхождение и проверяем если его нет
    char *istr = strstr(s, s1);
    if ((int)(istr - s) < 0){
        printf("No");
    }

    //Если оно есть то находим все вхождения
    while ((int)(istr - s) >= 0){
        s[(int)(istr - s)] = '&';
        printf("Position: %d\n", (int)(istr - s));
        istr = strstr(s, s1);
    }
}