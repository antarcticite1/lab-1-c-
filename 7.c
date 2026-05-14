#include <stdio.h>
#include <stdlib.h>

/* ќбъ€вить тип-структуру humen, включающую им€ человека, фамилию и год рождени€. 
ќбъ€вить два массива из четырЄх элементов типа humen. 
¬вести с консоли или из фай-ла элементы одного массива и построить на их основе другой, 
упор€дочив элементы по годам рождени€. 
¬ывести результат. */

struct humen {
    char name[50];
    char surname[50];
    int birth_year;
};

int main() {
    struct humen arr1[4];
    struct humen arr2[4];
    
    int i, j;
    struct humen temp;

    printf("Enter data for 4 people (Name, Surname, Year):\n");
    for (i = 0; i < 4; i++) {
        printf("Person %d: ", i + 1);
        scanf("%s %s %d", arr1[i].name, arr1[i].surname, &arr1[i].birth_year);
    }
    for (i = 0; i < 4; i++) {
        arr2[i] = arr1[i];
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3 - i; j++) {
            if (arr2[j].birth_year > arr2[j+1].birth_year) {
                temp = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp;
            }
        }
    }
    printf("Sorted list: \n");
    for (i = 0; i < 4; i++) {
        printf("%s %s, %d\n", arr2[i].name, arr2[i].surname, arr2[i].birth_year);
    }

    return 0;
}
