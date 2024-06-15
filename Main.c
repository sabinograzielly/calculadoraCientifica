#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Calculadora.c"
#include <math.h>

//constantes do tipo string
#define STR1 "Por favor, Introduza a operação usando notação polonesa (pós-fixada): "
#define MAX 100


int main(void){
    setlocale(LC_ALL, "Portuguese");
    struct pilha P1;
    inicializaPilha(&P1);

    char str[MAX];
    printf("\n %s", STR1);
    gets(str);

    double n1, n2, operando;
    double ff;
    int dimStr, i;
    
    dimStr=dimensaoStr(str);
    double Numero = 0.0;

    for(i=0; i<dimStr; i++){
    	
    	if (isdigit(str[i])) {
    		Numero = 10*Numero + str[i] - '0';
		}
		else {
			printf("%lf\n", Numero);
			if (isdigit(str[i-1])) push(&P1, Numero);
			Numero = 0;
			if(str[i] == '*'){
            	n1 = pop(&P1);
            	n2 = pop(&P1);
            	
            	push(&P1, (n1*n2));
            	printf("feed %lf\n", operando);
            }
        	else if(str[i] == '+'){
            	n1 = pop(&P1);
            	n2 = pop(&P1);
            printf("Desem %lf", n1);
            printf("Desem %lf", n2);
            push(&P1, (n1+n2));
            printf("feed %lf\n", operando);
            }
        else if(str[i] == '-'){
            n1 = pop(&P1);
            n2 = pop(&P1);
            push(&P1, (n1-n2));
            printf("feed %lf\n", operando);
        }
        else if(str[i] == '/'){
            n1 = pop(&P1);
            n2 = pop(&P1);
            push(&P1, (n1/n2));
            printf("feed %lf\n", operando);
        } 
		else if (str[i] == 'log') { // 'l' para log
            n1 = pop(&P1); printf ("%lf", log(n1));
            push(&P1, log(n1));
        } 
		else if (str[i] == 'sen') { // 's' para sen
            n1 = pop(&P1);
            push(&P1, sin(n1));
        } 
		else if (str[i] == 'cos') { // 'c' para cos
            n1 = pop(&P1);
            push(&P1, cos(n1));
        } 
		else if (str[i] == 'tan') { // 't' para tan
            n1 = pop(&P1);
            push(&P1, tan(n1));
        }
		}
    	

    } //For que percorre a String

    ff = pop(&P1);
    printf("\n\n O resultado da operação é: %lf", ff);
}
