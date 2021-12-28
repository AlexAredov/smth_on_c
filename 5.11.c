#include <stdio.h>
#include <stdlib.h>
//из строки в число
int main()
{
    //Создаем переменные
    char sss[10];
    scanf("%s", sss);
    int pos = 1;
    int n = 1;
    int i = 0;

    //Проверяем на минус
    if (sss[i] == '-'){
        pos = 0;
        i++;
    }

    //Перевод
    int res = 0;
    float res1 = 0;
    while (sss[i] != '\0'){
        //Если точка то пропускаем
        if (sss[i] == '.'){
            n = 0;
            i++;
        }
        if (n == 0){
            //После точки умножаем на 0.1
            int k = sss[i] - '0';
            res1 = res1 + k* 0.1;
        }
        else{
            //Все до точки делаем по обычному алгоритму
            int k = sss[i] - '0';
            res = res * 10 + k;
        }
        i++;
    }

    //Плюсуем результаты (до точки и после)
    float result = res + res1;

    //Проверка на минус
    if (pos == 0){
        result = result * -1;
    }

    //Вывод результата преобразования
    printf("%f", result);
    return 0;
}