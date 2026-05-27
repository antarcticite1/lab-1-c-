#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Создать текстовый файл с записями, включающие имя/фамилию человека, год рожде-ния, пол и рост (в метрах). 
Упорядочить элементы по году рождения, имени/фамилии, полу или росту. 
Вывести результат. 
Указать элемент, по которому следует упорядо-чить, через консоль. 
А также реализовать возможность задавать несколько полей для упорядочивания. */


struct humen {
    char name[50];
    char surname[50];
    int year;
    char gender[10];
    float height;
};

int compare(const void *a, const void *b, int field) {
    struct humen *h1 = (struct humen*)a;
    struct humen *h2 = (struct humen*)b;
    
    switch(field) {
        case 1:
            return h1->year - h2->year;
        case 2:
            return strcmp(h1->name, h2->name);
        case 3:
            return strcmp(h1->surname, h2->surname);
        case 4:
            return strcmp(h1->gender, h2->gender);
        case 5:
            if(h1->height > h2->height) return 1;
            if(h1->height < h2->height) return -1;
            return 0;
        default:
            return 0;
    }
}
int current_field;
int wrapper(const void *a, const void *b) {
    return compare(a, b, current_field);
}

int main() {
    struct humen *data;
    int n = 0;
    int field;
    FILE *file;
    char line[200];
    file = fopen("data.txt", "r");
    
    while(fgets(line, sizeof(line), file)) {
        n++;
    }
    fclose(file);
    data = (struct humen*)malloc(n * sizeof(struct humen));
    file = fopen("data.txt", "r");
    for(int i = 0; i < n; i++) {
        fscanf(file, "%s %s %d %s %f", 
               data[i].name, 
               data[i].surname, 
               &data[i].year, 
               data[i].gender, 
               &data[i].height);
    }
    fclose(file);

    printf("\nNot sortedе:\n");
    printf("--------------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%s %s %d %s %.2f\n", 
               data[i].name, 
               data[i].surname, 
               data[i].year, 
               data[i].gender, 
               data[i].height);
    }

    printf("\nSelect a field for sorting:\n");
    printf("1 - born year\n");
    printf("2 - name\n");
    printf("3 - surname\n");
    printf("4 - gender\n");
    printf("5 - height\n");
    printf("Your choice is: ");
    scanf("%d", &field);

    current_field = field;
    qsort(data, n, sizeof(struct humen), wrapper);

    printf("\nResult:\n");
    printf("--------------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%s %s %d %s %.2f\n", 
               data[i].name, 
               data[i].surname, 
               data[i].year, 
               data[i].gender, 
               data[i].height);
    }
    free(data);
    return 0;
}
