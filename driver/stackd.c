/* 
 * File:   stacktd.c
 * Author: cisituplusnobel
 *
 * Created on November 26, 2018, 4:40 AM
 */
#include "../include/stackt.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * driver stack
 */
int main(int argc, char** argv) {
    Stack stack;
    int input;
    infotypeStackt value;
    CreateEmptyStackt(&stack);

    printf("Tester\n");
    printf("----------\n");
    while (true) {
        printf("1 = Output\n2 = Is2\n3 = Operasi\n");
        scanf("%d", &input);
        switch (input) {
            case 1:
                printf("[stack] \n");
                PrintStackt(stack);
                printf("\n");
                break;
            case 2:
                printf("IsEmptyStackt(stack) = %d\n", IsEmptyStackt(stack));
                printf("IsFullStackt(stack) = %d\n", IsFullStackt(stack));
                break;
            case 3:
                printf("[stack] \n");
                PrintStackt(stack);
                printf("\n");
                printf("1 = Push\n2 = Pop\n3 = Reverse\n");
                scanf("%d", &input);
                switch (input) {
                    case 1:
                        if (!IsFullStackt(stack)) {
                            printf("push value: ");
                            scanf("%d", &value);
                            Push(&stack, value);
                        } else {
                            printf("Full stack");
                        }
                        printf("\n");
                        break;
                    case 2:
                        if (!IsEmptyStackt(stack)) {
                            Pop(&stack, &value);
                            printf("pop value: %d\n", value);
                        } else {
                            printf("Empty stack\n");
                        }
                        break;
                    case 3:
                        stack = Reverse(stack);
                        break;
                    default:
                        printf("Exit through illegal input.\n");
                        return EXIT_SUCCESS;
                }
                printf("[stack] \n");
                PrintStackt(stack);
                printf("\n");
                break;
            default:
                printf("Exit through illegal input.\n");
                return EXIT_SUCCESS;
        }
    }
    return (EXIT_SUCCESS);
}