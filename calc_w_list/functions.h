/*
 * functions.h
 *
 *  Created on: 22 мая 2020 г.
 *      Author: Ekaterina Tararsova
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
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


// подсчет чисел с выделением памяти
float *numbers(char sign, float *firstnum, float *secondnum){
    float *result;
    float var1, var2;
    result = malloc(sizeof(float));
    switch (sign) {
        case '+':
            result[0] = firstnum[0] + secondnum[0];
            return result;
        case '-':
            result[0] = firstnum[0] - secondnum[0];
            return result;
        case '*':
            result[0] = firstnum[0] * secondnum[0];
            return result;
        case '/':
            if (secondnum[0] != 0) {
                result[0] = firstnum[0] / secondnum[0];
                return result;
            }
            else {
                return 0;
            }
        case '^':
            var2 = 1;
            var1 = 1;
            for (int i=1;i<=secondnum[0];i++){
                var1 = var2;
                var2 = var1 * firstnum[0];}
            result[0] = var2;
            return result;
        case '!':
            var1 = 1;
            for(int i = 1; i<=firstnum[0]; i++)
            {var1 = var1 * i;}
            result[0] = var1;
            return result;
    }
    return firstnum;
    return secondnum;
    free(firstnum);
    free(secondnum);
    free(result);
}

// аналогичная функция для векторных значений
float *vectors(char sign, int size, float *vec1, float *vec2){
    float *resultV;
    switch (sign){
        case '+':
            resultV = malloc(size * sizeof(float));
            for (int i = 0; i < size; i++){
                resultV[i] = vec1[i] + vec2[i];
            }
            return resultV;
        case '-':
            resultV = malloc(size * sizeof(float));
            for (int i = 0; i < size; i++){
                resultV[i] = vec1[i] - vec2[i];
            }
            return resultV;
        case '*':
            resultV = malloc(sizeof(float));
            resultV[0] = 0;
            for (int i = 0; i < size; i++){
                resultV[0] += (vec1[i] * vec2[i]);
            }
            return resultV;
        }
    return vec1;
    return vec2;
    free(vec1);
    free(vec2);
    free(resultV);
}

float *unpacking(FILE *input, int size){ //считывает указатели и добавляет в переменную
    float *var;
    var = malloc(size * sizeof(float));
    for(int i = 0;i < size;i++){
        fscanf(input,"%f", &var[i]);
    }
    return var;
}

void addList(input_var *second, FILE *input){// добавление чисел
    input_var *tmp = malloc(sizeof(input_var));
    fscanf(input, " %c %c", &tmp->sign, &tmp->operation);
    //считывает определенную операцию и создает для нее отдельный сптсок с действиями для нее
    if (tmp->operation == 'v'){
        fscanf(input, " %i", &tmp->size);}
    else{
        tmp->size = 1;
    }
    if (tmp->sign != '!'){
        tmp->firstnum = unpacking(input, tmp->size);
        tmp->secondnum = unpacking(input, tmp->size);
    }
    else{
        tmp->firstnum = unpacking(input, tmp->size);
        tmp->secondnum = NULL;
    }
    tmp->next = NULL;
    second->next = tmp;
}


void addListRes(output_var *second_res, input_var *second){// считывает числа после операций
    output_var *tmp_res = malloc(sizeof(output_var));
    if (second->operation == 'v'){
        tmp_res->result = vectors(second->sign, second->size, second->firstnum, second->secondnum);
    }
    else{
        tmp_res->result = numbers(second->sign, second->firstnum, second->secondnum);
    }
    tmp_res->res_next = NULL;
    second_res->res_next = tmp_res;

}



#endif /* FUNCTIONS_H_ */
