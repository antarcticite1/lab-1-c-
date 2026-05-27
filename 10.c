#include <stdio.h>
#include <stdlib.h>

/* 	Написать программу вычисления максимального числа из введенных пользова-телем в виде одной строки.  
Использовать для этого макрос (без функции), 
на вход ко-торому подается массив чисел и их количество. */

#include <string.h>
#define FIND_MAX(arr, count, result) \
    do { \
        result = arr[0]; \
        for (int i = 1; i < count; i++) { \
            if (arr[i] > result) { \
                result = arr[i]; \
            } \
        } \
    } while(0)

int main() {
    char input[1000];
    double numbers[100];
    int count = 0;
    double max_value;
    char *token;
    
    printf("Enter the numbers: ");
    fgets(input, sizeof(input), stdin);

    token = strtok(input, " \n");
    while (token != NULL && count < 100) {
        numbers[count] = atof(token);
        count++;
        token = strtok(NULL, " \n");
    }
    
    if (count == 0) {
        printf("Error!\n");
        return 1;
    }

    FIND_MAX(numbers, count, max_value);
    printf("Max number is: %g\n", max_value);
    
    return 0;
}
