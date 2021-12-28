#include <stdio.h>
#include <corecrt_malloc.h>

int main()
{
    //Создаем переменные и вводим n и m с клавиатуры
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);

    //Выделение памяти. Сначала выделяем память для массива
    //Потом в каждой ячейке массива выделяем память для еще одного массива
    int ** A = malloc(n*sizeof(int*) + n*m*sizeof(int));
    char ** pc = A;
    pc += n*sizeof(int*);
    for (int i=0; i<n; i++)
        A[i] = pc + i*sizeof(m*sizeof(int));

    //Теперь у нас есть пустая матрица размерами mxn
    //Заполняем ее. Проходим по массиву и каждую ячейку вводим при промощи scanf
    int i, j;
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < m; j++ ) {
            printf("A[%d][%d]:", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    //Обычный вывод матрицы
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < m; j++ )
        {
            printf( "%d\t", A[i][j] );
        }
        printf( "\n" );
    }
}