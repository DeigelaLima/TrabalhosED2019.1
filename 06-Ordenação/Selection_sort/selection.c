#include <stdio.h>

//SELECTION -> Procura o menor ou o maior, dependendo do algoritmo e coloca na frente se for o menor 
//e atras se for o maior

//MACRO
#define incrementa_um(a,b) do{a++; b++;}while(0);//faça somente uma vez
//Encontra o menor [inicio, fim[ - intervalo aberto -> (vai ate um elemento antes do fim)
#define troca(a, b, tipo)//usando MACRO
    do{
        tipo aux = a;
        a = b;
        b = aux;
    }while(0)
int encontrar_imenor(int vetor[], int inicio, int fim){
    int imenor = inicio;
    for(int i = inicio + 1; i < fim; i++){
        if(vetor[i] < vetor[imenor]){
            imenor = i;
    return imenor;
        }
    }
}
int selection(int vetor[], int tamanho){
    //do{

    //}while(0);//executado so uma vez
}
int main(){
    int c = 4;
    int d = 7;
    troca(x, y, int);
    printf("%d %d\n", x, y);

    float f1 = 8.5;
    float f2 = 9.8;
    troca(f1, f2, float);
    printf("%f %f\n", f1, f2);

    char *c1 = "Uva";
    char *c2 = "Banana";
    troca(c1, c2, char *);
    printf("%s %s\n", c1, c2);

    /*if(0)
    incrementa_um(c, d);
    printf("Valor de c: %d\nValor de d: %d\n", c, d);*/

    return 0;
}