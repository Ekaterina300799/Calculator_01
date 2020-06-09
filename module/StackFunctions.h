/*
 * StackFunctions.h
 *
 *  Created on: 6 июн. 2020 г.
 *      Author: katri
 */

#ifndef STACKFUNCTIONS_H_
#define STACKFUNCTIONS_H_


#include <stdio.h>
#include <stdlib.h>

typedef struct result_stack {
    float result;
    struct result_stack *res_last;
} result_stack;


result_stack *head_stack = NULL;

void push_stack(float element){
    result_stack *tmp_stack = malloc(1* sizeof(result_stack));
    tmp_stack->result = element;
    if (head_stack == NULL) {
        tmp_stack->res_last = NULL;
        head_stack = tmp_stack;
    } else {
        tmp_stack->res_last = head_stack;
        head_stack = tmp_stack;
    }
}

float pop_elemet(void){
    result_stack *tmp;
    float data;
    tmp = head_stack;
    head_stack = head_stack->res_last;
    data = tmp->result;
    free(tmp);
    return data;
}


#endif /* STACKFUNCTIONS_H_ */
