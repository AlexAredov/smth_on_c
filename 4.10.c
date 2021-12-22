#include <stdio.h>
#include <string.h>
#include <corecrt_malloc.h>

int main()
{
    int n1;
    int m1;
    scanf("%d", &n1);
    scanf("%d", &m1);

    int n = n1;
    int m = m1;

    int ** A = malloc(n*sizeof(int*) + n*m*sizeof(int));
    char ** pc = A;
    pc += n*sizeof(int*);
    for (int i=0; i<n; i++)
        A[i] = pc + i*sizeof(m*sizeof(int));


    int i, j;
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < m; j++ ) {
            printf("A[%d][%d]:", i, j);
            //A[i][j] = i * j;
            scanf("%d", &A[i][j]);
        }
    }


    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < m; j++ )
        {
            printf( "%d\t", A[i][j] );
        }
        printf( "\n" );
    }
}