#include <stdio.h>
#include "xpaint.h"
#include "xvet.h"

//SELECTION -> Procura o menor ou o maior, dependendo do algoritmo e coloca na frente se for o menor 
//e atras se for o maior
#define troca(a,b, tipo) do{tipo troca = a; a = b; b = troca;}while(0)

//Encontra o menor [inicio, fim[ - intervalo aberto -> (vai ate um elemento antes do fim)
int encontrar_imenor(int vetor[], int tamanho,int inicio, int fim){
    int imenor = inicio;
    for(int i = inicio + 1; i < fim; i++){
        if(vetor[i] < vetor[imenor])
            imenor = i;
        xd_vet(vetor, tamanho,"yr", i, imenor);
    }
    return imenor;
}
void selection(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        xs_partition(i, tamanho -1);
        int imenor = encontrar_imenor(vetor, tamanho, i, tamanho);
        xd_vet(vetor, tamanho, "ry", imenor, i);
        troca(vetor[i], vetor[imenor], int);
        xd_vet(vetor, tamanho, "ry", imenor, i);
    }
}
void selection_maior(int vetor[], int tamanho){
    for(int i = tamanho -1; i > -1; i -=1){
        int imaior = i;
        for(int j = 0; j < i; j ++){//j < i -> olho os elementos antes de i para saber se eh o maior
            if(vetor[j] > vetor[imaior])
                imaior = j;
            xd_vet(vetor, tamanho, "ryg", imaior, i, j);
        }
        troca(vetor[imaior], vetor[i], int);
    }
}
int main(){
    x_open(600, 600);
    xs_log("imagens/");// salva as imagens(pasta)
    int tamanho = 40;
    int vetor[tamanho];
    //srand(0); 
    for(int i = 0; i < tamanho; i++)
        vetor[i] = xm_rand(10, 100);
        //vetor[i] = rand() % 191 + 10;//troca o intervalo
    xd_vet(vetor, tamanho, "");
    //selection(vetor, tamanho);
    selection_maior(vetor, tamanho);
    xd_vet(vetor, tamanho, "");
    x_close();
}