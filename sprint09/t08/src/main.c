#include "../inc/minilibmx.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printerr("usage: ./calc [operand1] [operation] [operand2]\n");
        return INCORRECT_OPERAND;
    }

    int operand1 = mx_atoi(argv[1]);
    int operand2 = mx_atoi(argv[3]);
    char operation = argv[2][0];

    t_operation operations[] = {
        {'-', mx_sub},
        {'+', mx_add},
        {'*', mx_mul},
        {'/', mx_div},
        {'%', mx_mod}};

    t_operation *selected_operation = NULL;
    for (int i = 0; i < (int)(sizeof(operations) / sizeof(operations[0])); i++) {
        if (operations[i].op == operation) {
            selected_operation = &operations[i];
            break;
        }
    }

    if (selected_operation == NULL) {
        printerr("error: incorrect operation\n");
        return INCORRECT_OPERATION;
    }

    if (!mx_isdigit(argv[1][0]) || !mx_isdigit(argv[3][0])) {
        printerr("error: invalid number\n");
        return INCORRECT_OPERAND;
    }

    if (operand2 == 0 && selected_operation->op == '/') {
        printerr("error: division by zero\n");
        return DIV_BY_ZERO;
    }

    int result = selected_operation->f(operand1, operand2);
    mx_printint(result);
    mx_printchar('\n');

    return 1;
}
