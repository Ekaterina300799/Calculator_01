/*
 * Calcul_w_list.c
 *
 *  Created on: 22 мая 2020 г.
 *      Author: Ekaterina Tarasova
 *      Descriptions: Калькулятор с вводом и выводом из файла. Добалена работа со списком. Данные считываются из файла(input.txt в нашем случае),
 *       доюавляются в список. После проведения операций результат записывается в другой список, а от туда попадает в другой файл(output.txt в нашем случае).
 *       Также все, необходимые для выполнения программы, функции импортируются из functions.h.
 */
#include "functions.h"


int main(){
    int repeat = 1;
    char inputfile[100], outputfile[100];
    FILE *input, *output;
    // Указатели для списка с данными для начала и ответа
    input_var *head, *second;
    output_var *head_res, *second_res;
    while(repeat == 1){ //start while for repeat
        printf("Enter name of input file:");
        scanf(" %s", inputfile);
        printf("Enter name of output file:");
        scanf(" %s", outputfile);
        input = fopen(inputfile,"r");
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
                   head_res->result=vectors(second->sign, second->size, second->firstnum, second->secondnum);
               }
           else{
               head_res->result=numbers(second->sign, second->firstnum, second->secondnum);
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
        }//end if in file
    printf("Do you want to continue? ('Yes'-tap 1, 'No'- tap 0): \n");
    scanf(" %i", &repeat);
    }// end while repeat
    return 0;
}
