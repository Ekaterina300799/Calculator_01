#include <stdio.h>
#include <stdlib.h>
int main(void)
{
 float firstnum, secondnum, var1, var2;
 char sign = '+';
 int repeat = 1;
 while(repeat == 1){
 printf("Select the first number:");
 scanf("%f", &firstnum);//Выбираем первое число.
 printf("Select the sign(+-*/^!):");
 scanf(" %c%*c", &sign);//Выбираем операцию.
 if (sign=='+'|| sign=='-' || sign=='*' || sign=='/' || sign=='^'){
     printf("Select the second number:");
     scanf("%f", &secondnum); //Выбираем второе число.
     switch(sign)
     {
     case'+':
         printf("Result: %f\n", firstnum+secondnum); //Выводим сумму
         break;
     case'-':
         printf("Result: %f\n", firstnum-secondnum); //Выводим разность
         break;
     case'*':
         printf("Result: %f\n", firstnum*secondnum); //Выводим произведение
         break;
     case'/':
         if( secondnum == 0){ //Действие при выборе нуля, которое позволяет выбрать числа занова.
             printf("Wrong! ");}
         else {
             printf("Result: %f\n", firstnum/secondnum); //Выводим деление
         }
         break;
     case'^':
         var1=1;
         var2=1;
         for(int var1=1; var1<=secondnum; var1++){
             var1=var2;
             var2=var1*firstnum;}
         printf("Result: %f\n", var2);// Выводим степень
         break;}
     }
 else if (sign=='!'){
     var1=0;
     var2=1;
     for(int var1=1; var1<=firstnum; var1++){
         var2=var2*firstnum;
         var1=var2;}
     printf("Result: %f\n", var2);} //Выводим факториал
else printf("Please select the sign again(+-*/^): \n");
 }
 printf("Do you want to continue? ('Yes'-tap 1, 'No'- tap 0): "); //Выбираем произвести нам операцию повторно или нет
 scanf("%i", &repeat);
 }
