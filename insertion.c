#include <stdio.h>
//insertion sort

//замена одного элемента массива на другой
void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main()
{
    int data[] = {2, 5, 1, 6, 3, 4};

    //вычисляем длину массива
    int size = sizeof(data)/sizeof(data[0]);

    //главный цикл берем каждый элемент массива
    for (int i = 1; i < size; i++){
        //записываем его в переменную key
        int key = data[i];
        int j = i - 1;
        //и проходим по всем элементам пока key меньше элементов
        while (data[j] > key && j >= 0){
            data[j + 1] = data[j];
            j--;
        }
        //ставим key на его место в массиве
        data[j + 1] = key;
    }

    //вывод массива
    for (int i = 0; i < size; i++){
        printf("%d",data[i]);
        printf("%s", " ");
    }
}