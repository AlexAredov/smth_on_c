#include <stdio.h>
#include <malloc.h>

int main()
{
    //Создаем переменные и вводим с клавиатуры
    int **a;
    int i, j, n, m;
    int s = 1;
    int c = 1;
    int d = 1;
    scanf("%d", &n);
    scanf("%d", &m);

    //Выделение памяти (как в 4.10)
    a = (int**)malloc(n * sizeof(int*));
    for (i = 0; i<n; i++)
        a[i] = (int*)malloc(m * sizeof(int));

    //Заполнение массива 0 для удобства
    for (i = 0; i<n; i++){
        for (j = 0; j<m; j++)
            a[i][j] = 0;
    }

    //Заполняем периметр матрицы по часовой стрелке
    for (int y = 0; y < n; y++){
        a[0][y] = s;
        s++;
    }
    for (int x = 1; x < m; x++) {
        a[x][n - 1] = s;
        s++;
    }
    for (int y = n - 2; y >= 0; y--) {
        a[m - 1][y] = s;
        s++;
    }
    for (int x = m - 2; x > 0; x--) {
        a[x][0] = s;
        s++;
    }

    //Заполняем центральные ячейки
    while (s < m * n) {
        while (a[c][d + 1] == 0) {
            a[c][d] = s;
            s++;
            d++;
        }
        while (a[c + 1][d] == 0) {
            a[c][d] = s;
            s++;
            c++;
        }
        while (a[c][d - 1] == 0) {
            a[c][d] = s;
            s++;
            d--;
        }
        while (a[c - 1][d] == 0) {
            a[c][d] = s;
            s++;
            c--;
        }
    }

    //Заполняем центральнуя ячейку
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            if (a[x][y] == 0) {
                a[x][y] = s;
            }
        }
    }

    //Бычный вывод массива
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}