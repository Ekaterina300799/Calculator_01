/*
 * Calcul_w_list.c
 *
 *  Created on: 9 июн. 2020 г.
 *      Author: Ekaterina Tarasova
 *      Descriptions: Модульный калькулятор с вводом и выводом из файла. Работа со списком, очередью и стеком.
 *       Данные считываются из файла(input_list.txt-для списка, input_sq.txt - для очереди и стека в нашем случае).
 *       Ответы записываются в файлы: output_list.txt(для списка), output_sq.txt(для очереди и стека).
 *       Замечание: Для корректной работы с очередью и стеком в файле ввода после окончания строки введите знак "." для перехода на новую строку для чтения.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>


#include "ListFunctions.h"
#include "QueueFunctions.h"
#include "StackFunctions.h"

int main(void){
    char inputfile[100], outputfile[100], cont = '+';
    FILE *input, *output;
    char *cut, *str_1;
    float element, firstnum, secondnum;
    input_var *head, *second;
    output_var *head_res, *second_res;

    printf("Choose container for work: list - tap l, stack and queue - q: ");
    scanf(" %c", &cont);
    printf("Enter name of input file:");
    scanf(" %s", inputfile);
    printf("Enter name of output file:");
    scanf(" %s", outputfile);
    input = fopen(inputfile, "r");
    switch(cont){
    case 'l':
        if(feof(input) == 0){ //if in file
           head = malloc(sizeof(input_var)); //выделение память для указателя head (ведет на первый элемент списка)
           //  метод sizeof вычисляет размер элемента
           //  метод malloc выделяет требуемое количество памяти
           fscanf(input, " %c %c",  &head->sign, &head->operation);
           //записываем отдельно данные для 1 элемента
           if (head->operation == 'v') {
               fscanf(input, " %i", &head->size);
           }
           else {
               head->size = 1;
           }

           if (head->sign != '!'){
               head->firstnum = unpacking(input, head->size);
               head->secondnum = unpacking(input, head ->size);
           }
           else{
               head->firstnum = unpacking(input, head->size);
               head->secondnum = NULL;
           }

           second = head;
           int n;
           while(feof(input) == 0){ //добавление элементов из файла, пока он не закончится
               addList(second, input);
              second = second->next;
              n+=1;
           }

           head_res = malloc(sizeof(output_var)); // выделение памяти для выхода
           second=head;
           if (second->operation == 'v'){//выбор функции
                   head_res->result=vectors_list(second->sign, second->size, second->firstnum, second->secondnum);
               }
           else{
               head_res->result=numbers_list(second->sign, second->firstnum, second->secondnum);
               }
           head_res->res_next = NULL;
           second = second->next;
           second_res = head_res;
           while(second != NULL){//добавление всех элементов в список с результатами(res)
               addListRes(second_res, second);
               second = second->next;
               second_res = second_res->res_next;
           }
           second = head;
           second_res = head_res;
           fclose(input);
           output = fopen(outputfile, "w");

           while(second != NULL){//запись ответа в output
               if(second->operation == 'v'){
                   fprintf(output, "(");
                   for (int i = 0; i < second->size; i++){
                       fprintf(output, " %.0f", second->firstnum[i]);
                   }
                   fprintf(output, ") %c (", second->sign);
                   for (int i = 0; i < second->size; i++){
                       fprintf(output, " %.0f", second->secondnum[i]);
                   }
                   fprintf(output, ") = ");
                   if (second->sign != '*'){
                       fprintf(output, "(");
                       for (int i = 0; i < second->size; i++){
                           fprintf(output, " %.0f", second_res->result[i]);
                       }
                       fprintf(output, ")\n");
                       }
                   else{
                       fprintf(output, " %.0f\n", second_res->result[0]);
                   }
               }//end if for v
               else if (second->operation == 's'){
                   fprintf(output, "%.0f\n", second_res->result[0]);
               }
               second = second->next;
               second_res = second_res->res_next;
          }//while sec!=0
          fclose(output);
        }
        break; //end of case l
    case 'q':
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
            output = fopen( outputfile, "w");
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


        break; //end case sq


    }// end switch container

}//end main
