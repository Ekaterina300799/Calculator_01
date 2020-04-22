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
     if (sign == '+'){
         printf("Select the second number:\n");
         scanf("%f", &secondnum);
         printf("Result: %f\n", firstnum+secondnum);
     }
     else if (sign == '-'){
         printf("Select the second number:\n");
         scanf("%f", &secondnum);
         printf("Result: %f\n", firstnum-secondnum);
     }
     else if (sign == '*'){
              printf("Select the second number:\n");
              scanf("%f", &secondnum);
              printf("Result: %f\n", firstnum*secondnum);
          }
     else if (sign == '/'){
              printf("Select the second number:\n");
              scanf("%f", &secondnum);
              if( secondnum == 0){
                  printf("Wrong! ");}
              else {
                  printf("Result: %f\n", firstnum/secondnum);
              }
          }
     else if (sign == '^'){
         printf("Select the second number:\n");
         scanf("%f", &secondnum);
         var1=1;
         var2=1;
         for(int var1=1; var1<=secondnum; var1++){
             var1=var2;
             var2=var1*firstnum;}
         printf("Result: %f\n", var2);

     }
     else if (sign == '!'){
         var1=0;
         var2=1;
         for(int i=1; i<=firstnum; i++){
             var2=var2*i;
             var1=var2;}
             printf("Result: %f\n", var2);}
     else{
         printf("Please select the sign again(+-*/^): \n");
     }
 printf("Do you want to continue? ('Yes'-tap 1, 'No'- tap 0): "); //Выбираем произвести нам операцию повторно или нет
 scanf("%i", &repeat);
 }
}
