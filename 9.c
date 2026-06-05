#include <stdio.h>
#include <stdlib.h>
/* Реализовать программу-калькулятор с возможностью выполнения арифметических действий (+, -), унарный и бинарный вариант. 
У пользователя запрашивается выраже-ние, например, "-123.5 + 4 - 456+56", программа должна решить выражение. 
Для разбо-ра входной строки использовать функцию strok. */
#include <string.h>

int main() {
    char input[256];
    char processed[512];
    int p_idx = 0;
    
    printf("Enter expression: ");
    scanf(" %[^\n]", input);

    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            if ((c == '+' || c == '-') && (i == 0 || input[i-1] == '+' || input[i-1] == '-' || input[i-1] == '*' || input[i-1] == '/')) {
                processed[p_idx++] = c;
            } else {
                processed[p_idx++] = ' ';
                processed[p_idx++] = c;
                processed[p_idx++] = ' ';
            }
        } else if (c != ' ') {
            processed[p_idx++] = c;
        }
    }
    processed[p_idx] = '\0';

    char *tokens[256];
    int token_count = 0;
    char *token = strtok(processed, " ");
    while (token != NULL) {
        tokens[token_count] = token;
        token_count++;
        token = strtok(NULL, " ");
    }
    double numbers[256];
    char operators[256];
    int num_count = 0;
    int op_count = 0;

    for (int i = 0; i < token_count; i++) {
        if (i % 2 == 0) {
            numbers[num_count] = atof(tokens[i]);
            num_count++;
        } else {
            operators[op_count] = tokens[i][0];
            op_count++;
        }
    }
    int i = 0;
    while (i < op_count) {
        if (operators[i] == '*' || operators[i] == '/') {
            if (operators[i] == '*') {
                numbers[i] = numbers[i] * numbers[i+1];
            } else {
                numbers[i] = numbers[i] / numbers[i+1];
            }

            for (int j = i; j < op_count - 1; j++) {
                operators[j] = operators[j+1];
                numbers[j+1] = numbers[j+2];
            }
            
            op_count--;
            num_count--;
        } else {
            i++;
        }
    }

    double result = numbers[0];
    for (int i = 0; i < op_count; i++) {
        if (operators[i] == '+') {
            result = result + numbers[i+1];
        } else if (operators[i] == '-') {
            result = result - numbers[i+1];
        }
    }

    printf("Result: %.2f\n", result);
    
    return 0;
}
