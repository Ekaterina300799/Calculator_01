#include <stdio.h>
#include <stdlib.h>
#include "QueueFunctions.h"


queue *queue_head = NULL;
queue *queue_tail = NULL;


int addelement_queue(FILE *input) {
    queue *tmp = malloc(1 * sizeof(queue));
    fgets(tmp->string, sizeof(tmp->string), input);
    tmp->next = NULL;
    if (queue_tail != NULL) {
        queue_tail->next = tmp;
        queue_tail = tmp;
    } else {
        queue_head = tmp;
        queue_tail = tmp;
    } return 1;
}

char *read_element(void) {
    if(queue_head != NULL) {
        char *data;
        data = queue_head->string;
        queue_head = queue_head->next;
        return data;
    } else {
        return NULL;
    }
}

int condition_check(char s){
    char sign[5] = {'+', '*', '^', '/', '!'};
    for (int i = 0; i != 5; i++){
        if (s == sign[i]){
            return 1;
        }
    }
    return 0;
}

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
