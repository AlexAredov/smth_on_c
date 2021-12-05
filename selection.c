#include <stdio.h>
//selection sort

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
    for (int i = 0; i < size - 1; i++){
        //считаем что он минимальный (записываем номер этого элемента)
        int min = i;
        //проходим по массиву еще раз
        for (int j = i + 1; j < size; j++){
            //и проверяем есть ли элемент меньше чем min?
            if(data[j] < data[min]){
                //если находим такой элемент, то записываем его в min (записываем номер этого элемента)
                min = j;
            }
        }
        //ставим настоящий минимум на свое место
        swap(&data[i], &data[min]);
    }

    //вывод массива
    for (int i = 0; i < size; i++){
        printf("%d",data[i]);
        printf("%s", " ");
    }
}