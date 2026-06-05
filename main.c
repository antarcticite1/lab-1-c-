#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int get_days_in_month(int year, int month) {
    struct tm time_struct = {0};
    time_struct.tm_year = year - 1900;
    time_struct.tm_mon = month;
    time_struct.tm_mday = 0;

    mktime(&time_struct);
    return time_struct.tm_mday;
}

void print_month_calendar(int year, int month) {
    struct tm time_struct = {0};
    time_struct.tm_year = year - 1900;
    time_struct.tm_mon = month - 1;
    time_struct.tm_mday = 1;

    mktime(&time_struct);

    char month_name[20];
    strftime(month_name, sizeof(month_name), "%B", &time_struct);

    printf("\n========== %d | %s ==========\n", year, month_name);
    printf("Mo Tu We Th Fr Sa Su\n");
    
    int total_days = get_days_in_month(year, month);
    int first_weekday = time_struct.tm_wday;

    if (first_weekday == 0) first_weekday = 7;
    first_weekday--;

    for (int i = 0; i < first_weekday; i++) {
        printf("   ");
    }

    for (int day = 1; day <= total_days; day++) {
        printf("%2d ", day);
        if ((day + first_weekday) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");
}

void print_year_calendar(int year) {
    printf("\n#################################\n");
    printf("       CALENDAR FOR %d\n", year);
    printf("#################################\n");
    
    for (int month = 1; month <= 12; month++) {
        print_month_calendar(year, month);
    }
}

void print_day_of_week(int year, int month, int day) {
    struct tm time_struct = {0};
    time_struct.tm_year = year - 1900;
    time_struct.tm_mon = month - 1;
    time_struct.tm_mday = day;

    mktime(&time_struct);
    
    char weekday_name[30];
    strftime(weekday_name, sizeof(weekday_name), "%A", &time_struct);

    printf("\nDate: %04d.%02d.%02d\n", year, month, day);
    printf("Day of week: %s\n\n", weekday_name);
}

void print_current_date() {
    time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);
    
    char weekday_name[30];
    strftime(weekday_name, sizeof(weekday_name), "%A", local_time);
    
    printf("\n=== CURRENT DATE ===\n");
    printf("Date: %04d.%02d.%02d\n", 
           local_time->tm_year + 1900,
           local_time->tm_mon + 1,
           local_time->tm_mday);
    printf("Day: %s\n\n", weekday_name);
}

void process_calendar_input(char *input) {
    input[strcspn(input, "\n")] = 0;

    if (strcmp(input, "now") == 0) {
        print_current_date();
        return;
    }

    int year = 0, month = 0, day = 0;
    int dot_count = 0;

    char *ptr = input;
    while (*ptr) {
        if (*ptr == '.') dot_count++;
        ptr++;
    }

    if (dot_count == 0) {
        sscanf(input, "%d", &year);
        print_year_calendar(year);
    }
    else if (dot_count == 1) {
        sscanf(input, "%d.%d", &year, &month);
        print_month_calendar(year, month);
    }
    else {
        sscanf(input, "%d.%d.%d", &year, &month, &day);
        print_day_of_week(year, month, day);
    }
}

int main() {
    char user_input[100];
    
    printf("=== CALENDAR PROGRAM ===\n");
    printf("Formats:\n");
    printf("  yyyy.mm.dd - day of week\n");
    printf("  yyyy.mm    - month calendar\n");
    printf("  yyyy       - year calendar\n");
    printf("  now        - current date\n\n");
    
    printf("Enter date: ");
    if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
        process_calendar_input(user_input);
    }
    
    return 0;
}
