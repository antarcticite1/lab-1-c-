#include <stdio.h>
#include <stdlib.h>

/* ќбъ€вить тип-структуру humen, включающую им€ человека, фамилию и год рождени€. 
ќбъ€вить два массива из четырЄх элементов типа humen. 
¬вести с консоли или из фай-ла элементы одного массива и построить на их основе другой, 
упор€дочив элементы по годам рождени€. 
¬ывести результат. */

#include <string.h>

struct humen {
    char name[50];
    char surname[50];
    int year;
};

int main() {
    struct humen a[4];
    struct humen b[4];
    int i, j;
    struct humen tmp;

    for(i = 0; i < 4; i++) {
        printf("Enter name, surname and year:\n");
        scanf("%s", a[i].name);
        scanf("%s", a[i].surname);
        scanf("%d", &a[i].year);
    }
    for(i = 0; i < 4; i++) {
        b[i] = a[i];
    }
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3 - i; j++) {
            if(b[j].year > b[j + 1].year) {
                tmp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = tmp;
            }
        }
    }
    
    printf("\nSorted:\n");
    for(i = 0; i < 4; i++) {
        printf("%s %s %d\n", b[i].name, b[i].surname, b[i].year);
    }

    return 0;
}
