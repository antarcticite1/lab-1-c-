#include <stdio.h>
#include <stdlib.h>

/* 	Написать программу вычисления максимального числа из введенных пользова-телем в виде одной строки.  
Использовать для этого макрос (без функции), 
на вход ко-торому подается массив чисел и их количество. */

#include <string.h>

#define FIND_MAXIMUM_VALUE(arr, size) ({ \
    double max_val = (arr)[0]; \
    int i; \
    for (i = 1; i < (size); i++) { \
        if ((arr)[i] > max_val) { \
            max_val = (arr)[i]; \
        } \
    } \
    max_val; \
})

int main() {
    char input[1000];
    int total_elements = 0;
    double numbers[1000];
    
    printf("enter: ");
    fgets(input, sizeof(input), stdin);
    
    char *a = strtok(input, " \n");
    
    while (a != NULL) {
        numbers[total_elements] = atof(a);
        total_elements++;
        a = strtok(NULL, " \n");
    }
    
    double max_value = FIND_MAXIMUM_VALUE(numbers, total_elements);
    printf("max number = %g\n", max_value); 
    
    return 0;
}
