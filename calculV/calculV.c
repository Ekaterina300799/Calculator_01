#include <stdio.h>
#include <stdlib.h>
int main(void)
{
 float *a, *b, res;
 int size;
 char sign;
 printf("Enter the size of the vectors: ");
 scanf("%i", &size);
 a = calloc(size,sizeof(float));
 for (int i=0; i<size; i++){
     printf("Enter the first vector: ");
     scanf("%f", &a[i]); }
 b = calloc(size,sizeof(float));
  for (int i=0; i<size; i++){
      printf("Enter the second vector: ");
      scanf("%f", &b[i]); }
 printf("Select the sign(+-):");
 scanf(" %c%*c", &sign);
 switch(sign){
 case '+':
    for (int i = 0; i < size; i++){
    printf("%f", a[i] + b[i]);}
    break;
 case '-':
    for (int i = 0; i < size; i++){
    printf("%f", a[i] - b[i]);}
    break;
 case '*':
     for (int i = 0; i < size; i++){
     res += a[i] * b[i];}
     printf("Result: %f\n", res);
     break;
}
}
