#include <stdio.h>
#include <stdlib.h>//rand
#include <time.h>

//INSERTION_SORT -> Lista ordenada, pega o que não está ordenado e coloca no meio das cartas ordenadas
#define troca(a,b, tipo) do{tipo troca = a; a = b; b = troca;}while(0)

void mostrar_vetor(int vetor[], int tamanho){
    printf("[ ");
    for(int i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);
    printf("]\n");    
}
void insertion_sort(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){     //i eh o elemento que quero posicionar dentro da lista ordenada
        for(int j = i; j > 0; j--){      // meu j não pode ser menor que zero(j > 0)| j serve para procurar  
            if(vetor[j] < vetor[j - 1]) //@o i dentro da lista ordenada, volto trazendo o elemento
                troca(vetor[j], vetor[j - 1], int);
                mostrar_vetor(vetor, tamanho);
        }
    }
}
int main(){
    srand((unsigned)time(NULL));//
    //srand(100);
    int tamanho = 10;
    int vetor[tamanho];
    for(int i = 0; i < tamanho; i++)
        vetor[i] = rand() % 100;
    printf("Vetor fora de ordem:\n");
    mostrar_vetor(vetor, tamanho);
    insertion_sort(vetor, tamanho);
    printf("\nVetor em ordem:\n");
    mostrar_vetor(vetor, tamanho);

}