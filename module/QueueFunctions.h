/*
 * QueueFunctions.h
 *
 *  Created on: 5 июн. 2020 г.
 *      Author: katri
 */

#ifndef QUEUEFUNCTIONS_H_
#define QUEUEFUNCTIONS_H_


typedef struct command_list {
    char string[50];
    struct command_list *next;
} queue;


int addelement_queue(FILE *input);
char *read_element(void);
int condition_check(char s);
float numb_operation(char sign, float firstnum, float secondnum);

#endif /* QUEUEFUNCTIONS_H_ */
