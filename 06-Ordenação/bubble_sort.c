#include <stdio.h>
#include <stdlib.h>//rand
#include <time.h>

//BUBBLE_SORT -> Empurra o maior para o final ou o menor para o começo, depende como queira
#define troca(a,b, tipo) do{tipo troca = a; a = b; b = troca;}while(0)

void mostrar_vetor(int vetor[], int tamanho){
    printf("[ ");
    for(int i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);
    printf("]\n");    
}
void sorte_bolha(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){//i eh o elemento que vou posicionar
        for(int j = tamanho - 1; j > i; j--){//trazendo o i para o comeco ou seja o menor elemento
            if(vetor[j] < vetor[j - 1])//comparando os dois elemento para colocar em ordem
                troca(vetor[j], vetor[j - 1], int);
                mostrar_vetor(vetor, tamanho);
        }
    }
}

int main(){
    srand((unsigned)time(NULL));
    int tamanho = 10;
    int vetor[tamanho];
    //srand(0); 
    for(int i = 0; i < tamanho; i++)
        vetor[i] = rand() % 100;
    printf("Vetor fora de ordem:\n");
    mostrar_vetor(vetor, tamanho);
    sorte_bolha(vetor, tamanho);
    printf("\nVetor em ordem:\n");
    mostrar_vetor(vetor, tamanho);
}