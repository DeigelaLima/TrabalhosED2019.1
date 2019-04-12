#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//SELECTION -> Procura o menor ou o maior, dependendo do algoritmo e coloca na frente se for o menor 
//e atras se for o maior
#define troca(a,b, tipo) do{tipo troca = a; a = b; b = troca;}while(0)


//Encontra o menor [inicio, fim[ - intervalo aberto -> (vai ate um elemento antes do fim)
int encontrar_imenor(int vetor[], int tamanho,int inicio, int fim){
    int imenor = inicio;
    for(int i = inicio + 1; i < fim; i++){
        if(vetor[i] < vetor[imenor])
            imenor = i;
    }
    return imenor;
}
void mostrar_lista(int vetor[], int tamanho){
    printf("[ ");
    for(int i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);
    printf("]\n");

}
void selection(int vetor[], int tamanho){//encontra o menor valor
    for(int i = 0; i < tamanho; i++){
        int imenor = encontrar_imenor(vetor, tamanho, i, tamanho);
        troca(vetor[i], vetor[imenor], int);
    }
}
int main(){
    srand((unsigned)time(NULL));
    int tamanho = 10;
    int vetor[tamanho];
    for(int i = 0; i < tamanho; i++)
        vetor[i] = rand() % 100;
    printf("Vetor fora de ordem:\n");
    mostrar_lista(vetor, tamanho);
    selection(vetor, tamanho);
    printf("\nVetor em ordem:\n");
    mostrar_lista(vetor, tamanho);
}