#include <stdio.h>
#include <stdlib.h>
int main(void){
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    float firstnum, secondnum, var1, var2;
    float *vec1, *vec2, res;
    char sign = '+', signV, choose, inputfile[100], outputfile[100], sv, chooseSV;
    int repeat = 1;
    int size, select;
    FILE *input, *output;
    while(repeat == 1){
        printf("Choose a data entry method: file input - f; console input - c: ");
        scanf(" %c", &choose);
        switch(choose){
        case 'f':
            printf("Enter name of input file:");
            scanf(" %s", inputfile);
            printf("Enter name of output file:");
            scanf(" %s", outputfile);
            input = fopen(inputfile,"r");
            output = fopen(outputfile, "w");
            while(feof(input) == 0){//while in file
                fscanf(input, " %c", &sign);
                fscanf(input, " %c", &sv);
                switch(chooseSV){
                case 's':
                    switch(sign){
                    case '+':
                        fscanf(input, " %f", &firstnum);
                        fscanf(input, " %f", &secondnum);
                        fprintf(output, "%f + %f = %f", firstnum, secondnum, firstnum + secondnum);
                        break;
                    case '-':
                        fscanf(input, " %f", &firstnum);
                        fscanf(input, " %f", &secondnum);
                        fprintf(output, "%f - %f = %f", firstnum, secondnum, firstnum - secondnum);
                        break;
                    case '*':
                        fscanf(input, " %f", &firstnum);
                        fscanf(input, " %f", &secondnum);
                        fprintf(output, "%f * %f = %f", firstnum, secondnum, firstnum * secondnum);
                        break;
                    case '/':
                        fscanf(input, " %f", &firstnum);
                        fscanf(input, " %f", &secondnum);
                        if (secondnum != 0){
                        fprintf(output, "%f / %f = %f", firstnum, secondnum, firstnum / secondnum);}
                        else{
                            fprintf(output, "Mistake! You can`t divide by 0.\n");
                        }
                        break;
                    case '^':
                        fscanf(input, " %f", &firstnum);
                        fscanf(input, " %f", &secondnum);
                        var1=1;
                        var2=1;
                        for(int var1=1; var1<=secondnum; var1++){
                            var1=var2;
                            var2=var1*firstnum;}
                        fprintf(output, "%f ^ %f = %f", firstnum, secondnum, var2);
                        break;
                    case '!':
                        fscanf(input, " %f", &firstnum);
                        var1=0;
                        var2=1;
                        for(int i=1; i<=firstnum; i++){
                            var2=var2*i;
                            var1=var2;}
                        fprintf(output, "%f! = %f", firstnum, var2);
                        break;
                    default:
                        fprintf(output, "Something wrong, try again.");
                        break;
                    }//switch sign in case 's' end
                    break; // case 's'
                case 'v':
                    vec1=malloc(size*sizeof(int));
                    vec2=malloc(size*sizeof(int));
                    switch(sign){
                    case '+':
                        fscanf(input, " %i", &size);
                        for(int i=0;i<size;i++)
                            fscanf(input, " %f",&vec1[i]);
                        for(int i=0;i<size;i++)
                            fscanf(input, " %f",&vec2[i]);
                        fprintf(output, "( ");
                        for(int i=0;i<size;i++)
                            fprintf(output, "%f ", vec1[i]);
                        fprintf(output, ") + ( ");
                        for(int i=0;i<size;i++)
                            fprintf(output, "%f ", vec2[i]);
                        fprintf(output, ") = ( ");
                        for(int i=0;i<size;i++)
                            fprintf(output, "%f ",vec1[i]+vec2[i]);
                        fprintf(output, ")");
                        break;
                    case '-':
                        fscanf(input, " %i", &size);
                        for(int i=0;i<size;i++)
                            fscanf(input, " %f",&vec1[i]);
                        for(int i=0;i<size;i++)
                            fscanf(input, " %f",&vec2[i]);
                        fprintf(output, "( ");
                        for(int i=0;i<size;i++)
                            fprintf(output, "%f ", vec1[i]);
                        fprintf(output, ") - ( ");
                        for(int i=0;i<size;i++)
                            fprintf(output, "%f ", vec2[i]);
                        fprintf(output, ") = ( ");
                        for(int i=0;i<size;i++)
                            fprintf(output, "%f ",vec1[i]-vec2[i]);
                        fprintf(output, ")");
                        break;
                    case '*':
                        fscanf(input, " %i", &size);
                        for(int i=0;i<size;i++)
                            fscanf(input, " %f",&vec1[i]);
                        for(int i=0;i<size;i++)
                            fscanf(input, " %f",&vec2[i]);
                        fprintf(output, "( ");
                        for(int i=0;i<size;i++)
                            fprintf(output, "%f ", vec1[i]);
                        fprintf(output, ") * ( ");
                        for(int i=0;i<size;i++)
                            fprintf(output, "%f ", vec2[i]);
                        fprintf(output, ") = ( ");
                        for(int i=0;i<size;i++){
                            res += vec1[i] * vec2[i];
                            fprintf(output, "%f ", res);}
                        fprintf(output, ")");
                        break;
                    }// switch sign in 'v' end
                    free(vec1);
                    free(vec2);
                break; //case 'v'
                }//switch chooseSV end
                fprintf(output, "\n");
            }//while in file
            fclose(input);
            fclose(output);
            break;// case 'f'
        case 'c':
            printf("Please, select a mode('number operation'-tap 1, 'vector operation'-tap 2):\n");
            scanf("%i", &select);
            if (select == 1){
                        printf("Select the first number:");
                        scanf("%f", &firstnum);
                        printf("Select the sign(+-*/^!):");
                        scanf(" %c%*c", &sign);
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

            break; //case 'c'
        } //switch file or console end

    printf("Do you want to continue? ('Yes'-tap 1, 'No'- tap 0): \n");
    scanf(" %i", &repeat);
    }//while repeat end
    free(vec1);
    free(vec2);
}
