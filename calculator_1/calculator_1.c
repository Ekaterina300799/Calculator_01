#include <stdio.h>
#include <stdlib.h>
int main(void){
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    float firstnum, secondnum, var1, var2;
    float *vec1, *vec2, res;
    char sign = '+', signV;
    int repeat = 1;
    int size, select;
    while(repeat == 1){ //Запускается цикл, благодаря которому мы можем выбирать повторить нам заново режим и операции или нет.
        printf("Please, select a mode('number operation'-tap 1, 'vector operation'-tap 2):\n"); //Выбираем режим.
        scanf("%i", &select);
        if (select == 1){ //При выборе 1 запускается операция с числами.
            printf("Select the first number:"); //Выбираем первое число.
            scanf("%f", &firstnum);
            printf("Select the sign(+-*/^!):"); //Выбираем знак.
            scanf(" %c%*c", &sign);
            //Далее при выборе знака мы вибираем второе число, если это необходимо.
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
        }
        else if(select == 2){ //При выборе 2 запускается векторна операция.
            printf("Enter the size of the vectors: "); //Выбираем размер вектора.
            scanf("%i", &size);
            vec1 = calloc(size,sizeof(float));
            for (int i=0; i<size; i++){
                printf("Enter the first vector: "); //Выбираем первый вектор.
                scanf("%f", &vec1[i]); }
            vec2 = calloc(size,sizeof(float));
            for (int i=0; i<size; i++){
                printf("Enter the second vector: "); //Выбираем второй вектор.
                scanf("%f", &vec2[i]); }
            printf("Select the sign(+-*):"); //Выбираем знак.
            scanf(" %c%*c", &signV);
            switch(signV){
            case '+':
               for (int i = 0; i < size; i++){
               printf("%f", vec1[i] + vec2[i]);}
               break;
            case '-':
               for (int i = 0; i < size; i++){
               printf("%f", vec1[i] - vec2[i]);}
               break;
            case '*':
                for (int i = 0; i < size; i++){
                res += vec1[i] * vec2[i];}
                printf("Result: %f\n", res);
                break;
            }
        }
        else{
            printf("Please select a mode again: 1 - num., 2 - vec: \n");
        }
    printf("Do you want to continue? ('Yes'-tap 1, 'No'- tap 0): \n");
    scanf(" %i", &repeat);
    }
    free(vec1);
    free(vec2);
    return 0;
}
