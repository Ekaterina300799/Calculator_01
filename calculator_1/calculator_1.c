#include <stdio.h>
#include <stdlib.h>
int main(void){
    float firstnum, secondnum, var1, var2;
    float *vec1, *vec2, res;
    char sign = '+', signV;
    int repeat = 1;
    int size, select;
    while(repeat == 1){
        printf("Please, select a mode('number operation'-tap 1, 'vector operation'-tap 2):");
        scanf("%i", &select);
        if (select == 1){
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
                for(int i=1; i<=firstnum; i++){
                    var2=var2*i;
                    var1=var2;}
                    printf("Result: %f\n", var2);} //Выводим факториал
            else {
                printf("Please select the sign again(+-*/^): \n");
            }
        }
        else if(select == 2){
            printf("Enter the size of the vectors: ");
            scanf("%i", &size);
            vec1 = calloc(size,sizeof(float));
            for (int i=0; i<size; i++){
                printf("Enter the first vector: ");
                scanf("%f", &vec1[i]); }
            vec2 = calloc(size,sizeof(float));
            for (int i=0; i<size; i++){
                printf("Enter the second vector: ");
                scanf("%f", &vec2[i]); }
            printf("Select the sign(+-*):");
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
    free(vec1);
    free(vec2);
    printf("Do you want to continue? ('Yes'-tap 1, 'No'- tap 0): ");
    scanf("%i", &repeat);
    }
}
