#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Реализовать программу-калькулятор с возможностью выполнения арифметических действий (+, -), 
унарный и бинарный вариант. 
У пользователя запрашивается выраже-ние, например, "-123.5 + 4 - 456+56", программа должна решить выражение.
 Для разбо-ра входной строки использовать функцию strok.*/
 
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char surname[50];
    int birthYear;
    char gender;
    float height;
} Person;

int sortField1 = 0;
int sortField2 = 0;

int compare(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    int result = 0;

    switch(sortField1) {
        case 1:
            result = p1->birthYear - p2->birthYear;
            break;
        case 2:
            result = strcmp(p1->name, p2->name);
            break;
        case 3:
            result = strcmp(p1->surname, p2->surname);
            break;
        case 4:
            result= p1->gender - p2->gender;
            break;
        case 5:
            if (p1->height > p2->height) result = 1;
            else if (p1->height < p2->height) result = -1;
            else result = 0;
            break;
    }

    if (result == 0 && sortField2 != 0) {
        switch(sortField2) {
            case 1:
                result = p1->birthYear - p2->birthYear;
                break;
            case 2:
                result = strcmp(p1->name, p2->name);
                break;
            case 3:
                result = strcmp(p1->surname, p2->surname);
                break;
            case 4:
                result = p1->gender - p2->gender;
                break;
            case 5:
                if (p1->height > p2->height) result = 1;
                else if (p1->height < p2->height) result = -1;
                else result = 0;
                break;
        }
    }   
    return result;
}

void printPerson(Person *p) {
    printf("%s %s, %d year, gender: %c, height: %.2f ?\n", 
           p->surname, p->name, p->birthYear, p->gender, p->height);
}

int main() {
    Person people[100];
    int count = 0;
    int numFields;
    FILE *file = fopen("data.txt", "r");
    
    while (fscanf(file, "%s %s %d %c %f", 
            people[count].name, 
            people[count].surname, 
            &people[count].birthYear,
            &people[count].gender, 
            &people[count].height) != EOF) {
        count++;
        if (count >= 100) break;
    }
    fclose(file); 
    printf(": %d\n\n", count);
    printf("How much fields for sorting? (1/2)? ");
    scanf("%d", &numFields);

    printf("\nSelect the first choice for sorting:\n");
    printf("1 - birth year\n");
    printf("2 - name\n");
    printf("3 - surname\n");
    printf("4 - gender\n");
    printf("5 - height\n");
    printf("Ypur choice is: ");
    scanf("%d", &sortField1);

    if (numFields == 2) {
        printf("\nSelect the second choice for sorting:\n");
        printf("1 - birth year\n");
        printf("2 - name\n");
        printf("3 - surname\n");
        printf("4 - gender?\n");
        printf("5 - height\n");
        printf("Your choice is: ");
        scanf("%d", &sortField2);
    }

    qsort(people, count, sizeof(Person), compare);
    printf("\n--- Sorted ---\n");
    Person *ptr = people;
    for (int i = 0; i < count; i++) {
        printPerson(ptr + i);
    }
    return 0;
}
