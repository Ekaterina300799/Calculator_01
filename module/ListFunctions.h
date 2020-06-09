/*
 * ListFunctions.h
 *
 *  Created on: 5 июн. 2020 г.
 *      Author: katri
 */

#ifndef LISTFUNCTIONS_H_
#define LISTFUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct start {
    char operation;
    char sign;
    int size;
    float *firstnum;
    float *secondnum;
    struct start *next;
} input_var;

typedef struct res {
    float *result;
    struct res *res_next;
} output_var;



float *numbers_list(char sign, float *firstnum, float *secondnum);
float *vectors_list(char sign, int size, float *vec1, float *vec2);
float *unpacking(FILE *input, int size);
void addList(input_var *second, FILE *input);
void addListRes(output_var *second_res, input_var *second);

#endif /* LISTFUNCTIONS_H_ */
