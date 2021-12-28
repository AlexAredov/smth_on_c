#include <stdio.h>
#include <string.h>

int main()
{
    //Создаем 2 строки вводим их с клавиатуры
    char A[100];
    char B[100];
    scanf("%s", A);
    scanf("%s", B);

    //Если первая строка больше второй выводим 1 > 2
    if(strlen(A) > strlen(B)){
        printf("%s", "1 > 2");
    }
    //Если вторая больше первой выводим 1 < 2
    else{
        printf("%s", "1 < 2");
    }
}