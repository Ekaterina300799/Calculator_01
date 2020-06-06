/*
 * calcQ.c
 *
 *  Created on: 4 июня 2020 г.
 *      Author: Ekaterina Tararsova
 */

#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <string.h>


typedef struct turn_command {
    char command[30];
    struct turn_command *next;
}queue;

typedef struct stack {
    float element;
    struct stack *last;
}stack;

//Глобальные указатели: head - начало, tail - окончание
queue *head = NULL;
queue *tail = NULL;

stack *head_stack = NULL;

//Функция для операций над числами
float numb_operation(char sign, float firstnum, float secondnum){
    float y;
    float res;
    switch (sign){
        case '+':
            res = firstnum + secondnum;
            return res;
        case '-':
            res = firstnum - secondnum;
            return res;
        case '*':
            res = firstnum * secondnum;
            return res;
        case '^':
            res = firstnum;
            if (secondnum != 0){
                for (int i = 1; i < secondnum; i++){
                    firstnum = firstnum * res;
                }
                return firstnum;
            } else{
                firstnum = 1;
                return firstnum;
            }

        case '/':
            res = firstnum / secondnum;
            return res;
        case '!':
            y = 1;
            for(int i = 1; i<=firstnum; i++){y = y * i;}
            res = y;
            return res;
    }
    return 0;
}

//Функция проверки операции
int condition_check(char s){
    char sign[5] = {'+', '*', '^', '/', '!'};
    for (int i = 0; i != 5; i++){
        if (s == sign[i]){
            return 1;
        }
    }
    return 0;
}

//Функция добавления в стeк
void push_stack(float element){
    stack *tmp_stack = malloc(1* sizeof(stack));
    tmp_stack->element = element;
    if (head_stack == NULL){
        tmp_stack->last = NULL;
        head_stack = tmp_stack;
    } else{
        tmp_stack->last = head_stack;
        head_stack = tmp_stack;
    }
}

//Функция изъятия из стэка
float pop_elemet(void){
    stack *tmp;
    float data;
    tmp = head_stack;
    head_stack = head_stack->last;
    data = tmp->element;
    free(tmp);
    return data;
}

//Функция чтения первого элемента очереди
char *read_element(void){
    if(head != NULL) {
        char *data;
        data = head->command;
        head = head->next;
        return data;
    } else{return NULL;}
}

//Функция добавление элемента в очередь
int addelement_queue(FILE *input){
    queue *tmp = malloc(1 * sizeof(queue));
    fgets(tmp->command, sizeof(tmp->command), input);
    tmp->next = NULL;
    if(tail != NULL){
        tail->next = tmp;
        tail = tmp;
    } else{
        head = tmp;
        tail = tmp;
    }
    return 1;
}


int main(void) {
    FILE *input, *output;
    char inputfile[100], outputfile[100];
    char *cut, *str_1;
    float element, firstnum, secondnum;
    printf("Enter name of input file:");
    scanf(" %s", inputfile);
    printf("Enter name of output file:");
    scanf(" %s", outputfile);
    input = fopen("input.txt", "r");
    if (!feof(input)){
        while (!feof(input)) {
            addelement_queue(input);
        }
        //Получаем первый элемент очереди и разбираем его на части, проводя операции и записывая в стэк
        str_1 = read_element();
        while (str_1 != NULL){
            for(int i = 0; i < 30; i++) {
                //Знак "." является символом окончания строки
                if (str_1[i] == '.') {break;}
                else{
                    //Проверка. если это операция, то берем два элемента и стэка, проводим операцию
                    //И записываем обратно в стэк
                    if (condition_check(str_1[i]) == 1) {
                        if (str_1[i] != '!') {
                            secondnum = pop_elemet();
                            firstnum = pop_elemet();
                        } else {
                            firstnum = pop_elemet();
                        }
                        element = numb_operation(str_1[i], firstnum, secondnum);
                        push_stack(element);
                        i++;
                    } else {
                        if (str_1[i] == '-' and str_1[i + 1] == ' ') {
                            secondnum = pop_elemet();
                            firstnum = pop_elemet();
                            element = numb_operation(str_1[i], firstnum, secondnum);
                            push_stack(element);
                            i++;
                        } else {
                            //Установили, что это число. Находим его и добавляем в стэк
                            //находим длинну среза
                            int k = i;
                            //Получаем длинну среза
                            while (str_1[k] != ' ') { k++; }
                            int len_arr = k - i;
                            //Начинаем заполнение
                            k = i;
                            cut = malloc(len_arr * sizeof(char));
                            for (int p = 0; p < len_arr; p++) {
                                cut[p] = str_1[k];
                                k++;
                            }
                            i = k;
                            element = atof(cut);
                            push_stack(element);}
                    }
                }
            }
            //Читаем следующий элемент
            str_1 = read_element();
        }
        output = fopen("output.txt", "w");
        //записываем результаты
        while (head_stack != NULL){
            element = pop_elemet();
            fprintf(output, "Result: %.0f\n", element);
        }
        return 1;
    }
    return 0;
    fclose(output);
    fclose(input);
}
