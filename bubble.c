#include <stdio.h>
//bubble sort

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

    //главный цикл: проходим по массиву столько раз, сколько элементов в массиве
    for (int i = 0; i < size; i++) {
        for(int i = 0; i < size - 1; i++){
            //сравниваем элемент с последующим, если данный элемент больше последующего меняем их местами
            if (data[i] > data[i + 1]){
                swap(&data[i], &data[i + 1]);
            }
        }
    }

    //вывод массива
    for (int i = 0; i < size; i++){
        printf("%d",data[i]);
        printf("%s", " ");
    }
}